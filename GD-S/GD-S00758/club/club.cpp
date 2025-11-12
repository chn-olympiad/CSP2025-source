#include<bits/stdc++.h>
using namespace std;
int t,n,top;
int a[100005],b[100005],c[100005],x;
int dfs(int va,int vb,int vc,int ca,int cb,int cc,int x){
	if(x==n+1){
//		cout<<va+vb+vc<<endl;
		return va+vb+vc;
	}
	int n1,n2,n3;
	if(ca+1<=top) n1=dfs(va+a[x],vb,vc,ca+1,cb,cc,x+1);
	if(cb+1<=top) n2=dfs(va,vb+b[x],vc,ca,cb+1,cc,x+1);
	if(cc+1<=top) n3=dfs(va,vb,vc+c[x],ca,cb,cc+1,x+1);
	return max(n1,max(n2,n3));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		top=n/2;
		x=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		cout<<dfs(0,0,0,0,0,0,1)<<endl;
	}
	return 0;
}

