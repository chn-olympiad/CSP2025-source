#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,ans;

struct node{
	int p,dex;
};
bool cmp(node a,node b){
	return a.dex>b.dex;
}
bool vis[N];
node fir[N],sed[N],thd[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>fir[i].dex>>sed[i].dex>>thd[i].dex;
			vis[i]=0;
			fir[i].p=sed[i].p=thd[i].p=i;
		}
		sort(fir+1,fir+1+n,cmp);
		sort(sed+1,sed+1+n,cmp);
		sort(thd+1,thd+1+n,cmp);
		int i=1,j=1,k=1,per1=0,per2=0,per3=0;
		ans=0;
		while(true){
			node x=fir[i],y=sed[j],z=thd[k];
			if(per1+per2+per3==n)
				break;
			if(x.dex>y.dex && x.dex>z.dex && per1<n/2){
				if(!vis[x.p]){
					vis[x.p]=1;
					ans+=x.dex,per1++;
				}
				i++;
			}
			else if(y.dex>z.dex && per2<n/2){
				if(!vis[y.p]){
					vis[y.p]=1;
					ans+=y.dex,per2++;
				}
				j++;
			}
			else if(per3<n/2){
				if(!vis[z.p]){
					vis[z.p]=1;
					ans+=z.dex,per3++;
				}
				k++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
