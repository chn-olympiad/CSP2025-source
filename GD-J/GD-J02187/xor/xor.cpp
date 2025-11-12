#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],len,ans,m;
struct w{
	int l,r;
}sum[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
		if(a[i]==k)sum[++len].l=i,sum[len].r=i;
	}
	if(m==0&&k==0){
		cout<<n;
		return 0; 
	} 
	int x=a[1];
	for(int i=2;i<=n;i++){
		x^=a[i];
		for(int j=1;j<i;j++){
			x^=a[j];			
			if(x==k&&j+1!=i)sum[++len].l=j+1,sum[len].r=i;
		}
		for(int j=1;j<i;j++)x^=a[j];
	}
	cout<<len;
}
