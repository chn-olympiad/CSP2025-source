#include<bits/stdc++.h>
using namespace std;

int t,n,a[100005][3],sum,c[3];
struct xx{
	int p,aid,iid;
}x[100005];
bool cmp(xx xa,xx xb){
	return xa.p>xb.p;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][1]>=a[i][2]){
				x[i].aid=0;
				x[i].iid=1;
				x[i].p=a[i][0]-a[i][1];
				sum+=a[i][1];
			}
			else if(a[i][0]>=a[i][2]&&a[i][2]>=a[i][1]){
				x[i].aid=0;
				x[i].iid=2;
				x[i].p=a[i][0]-a[i][2];
				sum+=a[i][2];
			}
			else if(a[i][1]>=a[i][0]&&a[i][0]>=a[i][2]){
				x[i].aid=1;
				x[i].iid=0;
				x[i].p=a[i][1]-a[i][0];
				sum+=a[i][0];
			}
			else if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][0]){
				x[i].aid=1;
				x[i].iid=2;
				x[i].p=a[i][1]-a[i][2];
				sum+=a[i][2];
			}
			else if(a[i][2]>=a[i][0]&&a[i][0]>=a[i][1]){
				x[i].aid=2;
				x[i].iid=0;
				x[i].p=a[i][2]-a[i][0];
				sum+=a[i][0];
			}
			else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][0]){
				x[i].aid=2;
				x[i].iid=1;
				x[i].p=a[i][2]-a[i][1];
				sum+=a[i][1];
			}
		}
		sort(x+1,x+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(c[x[i].aid]<n/2){
				c[x[i].aid]++;
				sum+=x[i].p;
			}
			else{
				c[x[i].iid]++;
			}
		}
		cout<<sum<<"\n";
		sum=0;
		c[0]=c[1]=c[2]=0;
	}
	return 0;
} 
