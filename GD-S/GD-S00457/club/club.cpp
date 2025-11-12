#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n,ans=0,s=0;cin>>n;
		int a[n+5][5]={0},c[5]={0};bool b[n+5]={0};
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		while(++ans<=n){
			int maxn=0,maxx,maxy;
			for(int i=1;i<=n;i++)
				if(!b[i])
					for(int j=1;j<=3;j++)
						if(c[j]+1<=n/2&&a[i][j]>maxn){
							maxn=a[i][j];
							maxx=i;
							maxy=j;
						}
			if(maxn==0)break;
			b[maxx]=1;
			c[maxy]++;
			s+=a[maxx][maxy];
//			cout<<maxx<<"  pp "<<maxy<<endl;
		}cout<<s<<endl;
	}
	return 0;
}
