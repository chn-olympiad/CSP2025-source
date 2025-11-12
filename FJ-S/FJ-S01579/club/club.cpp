#include<bits/stdc++.h>
using namespace std;
#define int long long

int t,n,sum,a1,a2,a3;
bool a12,a13,a23;
int a[100001][3],xg[3][100001];

bool compare(int a,int b){
	return a>b;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin>>a[i][j];
		    if(a[i][1]>=a[i][2]) a12=1;
		    if(a[i][1]>=a[i][3]) a13=1;
		    if(a[i][2]>=a[i][3]) a23=1;
		    xg[1][i]=xg[2][i]=xg[3][i]=0;
		    if(a12&&a13){
		    	++a1;
		    	sum+=a[i][1];
		    	xg[1][i]+=a[i][1]-max(a[i][2],a[i][3]);
			}
		    if(!a12&&a23){
		    	++a2;
		    	sum+=a[i][2];
		    	xg[2][i]+=a[i][2]-max(a[i][1],a[i][3]);
			}
		    if(!a13&&!a23){
		    	++a3;
		    	sum+=a[i][3];
		    	xg[3][i]+=a[i][3]-max(a[i][1],a[i][2]);
			}
	        a12=a13=a23=0;
		}
		if(a1>n/2){
			sort(xg[1]+1,xg[1]+n+1,compare);
			for(int i=n/2+1;i<=a1;i++) sum-=xg[1][i];
		}
		if(a2>n/2){
			sort(xg[2]+1,xg[2]+n+1,compare);
			for(int i=n/2+1;i<=a2;i++) sum-=xg[2][i];
		}
		if(a3>n/2){
			sort(xg[3]+1,xg[3]+n+1,compare);
			for(int i=n/2+1;i<=a3;i++) sum-=xg[3][i];
		}
	    cout<<sum<<"\n";
	    sum=0;
	    a1=a2=a3=0;
	}
	return 0;
}
