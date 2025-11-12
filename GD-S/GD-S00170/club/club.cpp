#include<cstdio>
#include<cstring>

#include<algorithm>

constexpr int maxn=1e5+7;

int A[maxn][3];

struct info{
	int firstp,max,sec;
	bool operator<(info rhs)const{
		if(firstp!=rhs.firstp) return firstp<rhs.firstp;
		return max-sec<rhs.max-rhs.sec;
	}
}list[maxn];

void slove()
{
	int N;scanf("%d",&N);
	
	for(int i=0;i<N;i++)
		for(int j=0;j<3;j++)
			scanf("%d",&A[i][j]);
			
	memset(list,0,sizeof(list));
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<3;j++)
			if(A[i][j]>list[i].max){
				list[i].sec=list[i].max;
				list[i].max=A[i][j];
				list[i].firstp=j;
			}
			else if(A[i][j]>list[i].sec){
				list[i].sec=A[i][j];
			}
	}
	
	int ans=0;
	int cnt[3]={0,0,0};
	for(int i=0;i<N;i++){
		cnt[list[i].firstp]++;
		ans+=list[i].max;
	}
	
	int over=-1;
	for(int j=0;j<3;j++)
		if(cnt[j]>N/2)
			over=j;
		
	if(~over)
	{
		std::sort(list,list+N);
		int start=0;
		while(list[start].firstp<over) start++;
		for(int i=0;i<cnt[over]-N/2;i++)
			ans-=list[start+i].max-list[start+i].sec;
	}
	
	printf("%d\n",ans);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T;scanf("%d",&T);
	
	while(T--) slove();
	
	return 0;
}
