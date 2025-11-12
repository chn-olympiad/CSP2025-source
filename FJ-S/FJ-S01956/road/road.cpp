#include<bits/stdc++.h>
using namespace std;

long long n,m,k,ans=LONG_LONG_MAX;
bool book[100005];
long long lu[10005][10005];

struct cheng{
	long long summ,num,cnt;
}fir,now,ne_xt;

void bfs(long long a,long long b,long long c){
	queue<cheng> qq;
	fir.num=b;
	fir.summ=a;
	fir.cnt=c;
	qq.push(fir);
	while(!qq.empty()){
		now=qq.front();
		qq.pop();
		if(now.cnt==n){
			ans=min(ans,now.summ);
//			cout<<now.num<<' '<<now.cnt<<" "<<now.summ<<"\n";			
			continue;
		}
		for(int i=1;i<=n;i++){
			if(lu[now.num][i]==LONG_LONG_MAX)
				continue;
			if(i==now.num)
				continue;
			ne_xt={now.summ+lu[now.num][i],i,now.cnt+1};	
			if(book[i])
				ne_xt.cnt--;
			else	
				book[i]=true;		
			qq.push(ne_xt);
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			lu[i][j]=LONG_LONG_MAX;	
	for(int i=1;i<=m;i++){
		long long a,b,c;
		cin>>a>>b>>c;
		lu[a][b]=min(lu[a][b],c);
		lu[b][a]=min(lu[a][b],c);
	}
	for(int i=1;i<=k;i++){
		long long a,b[10005]={0};
		cin>>a;
		for(int j=1;j<=n;j++)
			cin>>b[j];
		for(int j=1;j<=n;j++){
			for(int kk=1;kk<=n;kk++){
				if(kk==j)
					continue;
				long long hua=b[j]+b[kk]+a;
//				cout<<j<<' '<<kk<<' '<<hua<<"\n";
				lu[j][kk]=min(lu[j][kk],hua);
				lu[kk][j]=min(lu[kk][j],hua);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout<<lu[i][j]<<' ';
//		cout<<"\n";
//	}
	book[1]=true;
	bfs(0,1,1);
	if(ans==LONG_LONG_MAX)
		cout<<0;
	else
		cout<<ans;
	return 0;
}
