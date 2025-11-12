#include<bits/stdc++.h>
using namespace std;
int t,n,p[3][100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int sum=0,cnt[3],k=-1;
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			int mn=max(a,max(b,c));
			sum+=mn;
			if(c==mn)p[2][++cnt[2]]=max(a-c,b-c);
			else if(b==mn)p[1][++cnt[1]]=max(a-b,c-b);
			else if(a==mn)p[0][++cnt[0]]=max(c-a,b-a);
		}
		if(cnt[0]>n/2)k=0;
		if(cnt[1]>n/2)k=1;
		if(cnt[2]>n/2)k=2;
		if(k==-1)printf("%d\n",sum);
		else {
			sort(p[k]+1,p[k]+1+cnt[k]);
			for(int i=cnt[k];i>n/2;i--)sum+=p[k][i];
			printf("%d\n",sum);
		}
	}
	return 0;
}
