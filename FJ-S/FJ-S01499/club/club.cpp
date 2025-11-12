#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,a[N][4],c[N][4],ans=0;;
void fs(int i)
{
	if(a[i][3]>a[i][2]){
		swap(a[i][3],a[i][2]);
		swap(c[i][3],c[i][2]);
	}
	if(a[i][2]>a[i][1]){
		swap(a[i][2],a[i][1]);
		swap(c[i][2],c[i][1]);
	}
	if(a[i][3]>a[i][2]){
		swap(a[i][3],a[i][2]);
		swap(c[i][3],c[i][2]);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		int b[N][3],d[4]={0};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				c[i][j]=j;
			}
			fs(i);
			d[c[i][1]]++;
			b[d[c[i][1]]][c[i][1]]=a[i][1];
			ans+=a[i][1];
		}
		if(d[1]<=n/2&&d[2]<=n/2&&d[3]<=n/2)cout<<ans<<endl;
		else{
			while(d[1]>n/2){
				int minn=N,x=0;
				for(int i=1;i<=d[1];i++)
					if(b[i][1]<minn){
						minn=b[i][1];
						x=i;
					}
				ans-=minn;
				b[x][1]=N;
				d[1]--;d[c[x][2]]++;
				b[d[x]][c[x][2]]=a[x][2];
			}
			while(d[2]>n/2){
				int minn=N,x=0;
				for(int i=1;i<=d[2];i++)
					if(b[i][1]<minn){
						minn=b[i][2];
						x=i;
					}
				ans-=minn;
				b[x][2]=N;
				d[2]--;d[c[x][2]]++;
				b[d[x]][c[x][2]]=a[x][2];
			}
			while(d[3]>n/2){
				int minn=N,x=0;
				for(int i=1;i<=d[3];i++)
					if(b[i][3]<minn){
						minn=b[i][3];
						x=i;
					}
				ans-=minn;
				b[x][3]=N;
				d[3]--;d[c[x][2]]++;
				b[d[x]][c[x][2]]=a[x][2];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
