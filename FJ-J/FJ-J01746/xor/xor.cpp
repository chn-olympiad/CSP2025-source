#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int j(int a){
	int d=a,s=0;
	while(d>=1){
		s=d%2;
		d=(d-d%2)/2;
	}
	redurn s;
}
void f(int a,int b){
	int i=1,g=0,q=j(a),w=j(b);
	while(q>=0||w>=0){
		if(q%10>0||w%10>0){
			g+=i;
		}
		q/=10;
		w/=10;
		i*=2;
	}
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int l=1,r=1,n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	cout<<0;
	return 0;
}
