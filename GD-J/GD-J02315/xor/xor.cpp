#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500011];
int b[500011];
void solve(int l,int r,int c){
	if(l>r || r-l<c)
		return ;
	int last=l;
	for(int i=l;i+c<=r;i++){
		int j=i+c;
//		cout<<k<<"   w  "<<' '<<c<<endl;
		if( int(b[j]^b[i-1] )==k){
//			cout<<i<<' '<<j<<" "<<b[j]<<' '<<b[i-1]<<' '<<int(b[j]^b[i-1])<<endl;
			ans++;
			solve(last,i-1,c+1);
			last=j+1;
			i=j;	
		}
	}
	solve(last,r,c+1);
	return ;
}
int main(){
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]^a[i];
//		cout<<b[i]<<' ';
	}
//	cout<<endl; 
	solve(1,n,0);
	cout<<ans;
	return 0;
}
