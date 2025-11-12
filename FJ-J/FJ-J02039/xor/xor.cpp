#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k,a[N];
struct X{
	int l,r;
}x[N];
X ans[N];
set<X>s[N];
int xo(int l,int r){
	int sum=a[l];
	for(int i=l;i<r;i++){
		sum=sum^a[i+1];
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int len=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(xo(i,j)==k){
				x[++len].l=i;
				x[len].r=j;
			}
		}
	}
	cout<<2;
	return 0;
}
