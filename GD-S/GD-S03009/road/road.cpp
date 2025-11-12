#include<bits/stdc++.h>
using namespace std;
int u[1000005],v[1000005],w[1000005],c[12],q[100005],a[12][1000005],m,s=0;
bool b[1000002];
long long f(int n,int k){
//	if(k==s)return 0;
	long long ans=0;
	int i;
	if(n==0){
    	for(i=1;u[i]!=k;i++);
	    for(;u[i]==k;i++){
	    	ans=max(ans,(long long)w[i]);
		}
		return ans;
	}
	for(i=1;u[i]!=k;i++);
	for(;u[i]==k;i++){
		if(b[v[i]]==0){
    		b[v[i]]=1;
	    	ans=max(ans,f(n-1,v[i]));
		    b[v[i]]=0;
		}
	}
	return ans+w[k];
}

int main(){
	int n,k;
	cin>>n>>m>>k;
	s=n;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		if(u[i]>v[i])swap(u[i],v[i]);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
    	for(int j=1;j<=n;j++){
    		cin>>a[i][j];
    	}
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			if(u[j]==i){
				swap(u[j],u[++q[i]]);
				swap(v[j],v[q[i]]);
				swap(w[j],w[q[i]]);
			}
		}
		for(int j=s+1;j<=s+q[i];j++){
			if(v[j]>v[j+1]){
				swap(v[j],v[j+1]);
				swap(w[j],w[j+1]);
			}
		}
		s+=q[i];
	}
	b[1]=1;
	cout<<f(n-1,1);
}
