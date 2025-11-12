#include<bits/stdc++.h>
using namespace std;
int m[4][100005],bi,n[5];
long long f(int a,int b,int c,int s){
	if(n[bi]==a+b+c+1){
    	int ans=0;
    	if(a<n[bi]/2)ans=m[1][s];
	    if(b<n[bi]/2)ans=max(ans,m[2][s]);
	    if(c<n[bi]/2)ans=max(ans,m[3][s]);
	    return ans;
	}
	long long ans=0;
	if(a<n[bi]/2)ans=f(a+1,b,c,s+1)+m[1][s];
	if(b<n[bi]/2)ans=max(ans,f(a,b+1,c,s+1)+m[2][s]);
	if(c<n[bi]/2)ans=max(ans,f(a,b,c+1,s+1)+m[3][s]);
	return ans;
}
int main(){
	int t;
	cin>>t;
	for(bi=1;bi<=t;bi++){
    	cin>>n[bi];
    	int ans=0;
		for(int c=1;c<=n[bi];c++){
			cin>>m[1][c]>>m[2][c]>>m[3][c];
		}
		ans=f(0,0,0,1);
		cout<<ans<<endl;
	}
}
