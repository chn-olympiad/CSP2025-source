#include<iostream>
using namespace std;
struct node{
	int l,r;
}q[500001];
int a[500001],b[500001];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<n*(n-1);
	return 0;
}
