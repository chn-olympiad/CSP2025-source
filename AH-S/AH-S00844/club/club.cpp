#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int t,n,ans;
struct node{
	int p[3];
}a[100005];
int x[100005],y[100005],z[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		x[0]=y[0]=z[0]=ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].p[0]>>a[i].p[1]>>a[i].p[2];
			if(a[i].p[0]>=a[i].p[1]&&a[i].p[0]>=a[i].p[2]){
				x[++x[0]]=a[i].p[0]-max(a[i].p[1],a[i].p[2]);
				ans+=a[i].p[0];
			}
			else if(a[i].p[1]>=a[i].p[2]&&a[i].p[1]>=a[i].p[0]){
				y[++y[0]]=a[i].p[1]-max(a[i].p[0],a[i].p[2]);
				ans+=a[i].p[1];
			}
			else if(a[i].p[2]>=a[i].p[1]&&a[i].p[2]>=a[i].p[0]){
				z[++z[0]]=a[i].p[2]-max(a[i].p[1],a[i].p[0]);
				ans+=a[i].p[2];
			}
		}
		if(x[0]>n/2){
			sort(x+1,x+x[0]+1);
			for(int j=1;j<=x[0]-n/2;j++){
				ans-=x[j];
			}
		}
		else if(y[0]>n/2){
			sort(y+1,y+y[0]+1);
			for(int j=1;j<=y[0]-n/2;j++){
				ans-=y[j];
			}
		}
		else {
			sort(z+1,z+z[0]+1);
			for(int j=1;j<=z[0]-n/2;j++){
				ans-=z[j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
