#include<bits/stdc++.h>
using namespace std;

long long t,n,k,s,dp[100005][5],q[5],w[5];
struct N{
	long long x[2],y[2],z[2];
}a[100005];
bool cmp(N X,N Y){
	if(X.x[0]!=Y.x[0]) return X.x[0]>Y.x[0];
	if(X.y[0]!=Y.y[0]) return X.y[0]>Y.y[0];
	if(X.z[0]!=Y.z[0]) return X.z[0]>Y.z[0];
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		k=n/2,s=0;
		q[1]=q[2]=q[3]=0;
		memset(w,0,sizeof(w));
		for(int i=1;i<=n;i++){
			cin>>a[i].x[0]>>a[i].y[0]>>a[i].z[0];
			a[i].x[1]=1,a[i].y[1]=2,a[i].z[1]=3;
			if(a[i].y[0]<a[i].z[0]) swap(a[i].y[0],a[i].z[0]),swap(a[i].y[1],a[i].z[1]);
			if(a[i].x[0]<a[i].y[0]) swap(a[i].x[0],a[i].y[0]),swap(a[i].x[1],a[i].y[1]);
			if(a[i].y[0]<a[i].z[0]) swap(a[i].y[0],a[i].z[0]),swap(a[i].y[1],a[i].z[1]);
		} sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(w[a[i].x[1]]<k) w[a[i].x[1]]++,s+=a[i].x[0];
			else w[a[i].y[1]]++,s+=a[i].y[0];
		} cout<<s<<endl;
	}
	return 0;
}
