#include<bits/stdc++.h>
using namespace std;
inline int maxn(int x,int y){return ((x<y)?x:y);}
const int N=1e5+5;
struct node{
	int w,ind,c;
}ans[N*3];
int ch[N],n,a[N][5],tans,al[5];
int cmp(node x,node y){return x.w>y.w;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		memset(ch,0,sizeof(ch));
		memset(al,0,sizeof(al));
		tans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			a[i][1]=x,a[i][2]=y,a[i][3]=z;
			ans[i*3-2]={.w=maxn(x-y,x-z),.ind=i,.c=1};
			ans[i*3-1]={.w=maxn(y-x,y-z),.ind=i,.c=2};
			ans[i*3]={.w=maxn(z-y,z-x),.ind=i,.c=3};
		}
		sort(ans+1,ans+n*3+1,cmp);
		for(int i=1;i<=n*3;i++)
		{
			int temp=ans[i].c,inx=ans[i].ind;
			if(!ch[inx]&&al[temp]<n/2)
			{
				tans+=a[inx][temp];
				ch[inx]=temp;
				al[temp]++;
			}
		}
		cout<<tans<<'\n';
	}
	return 0;
}
