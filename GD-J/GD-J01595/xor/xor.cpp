#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
long long ans=0;
int c1[500005];
int c2[500005];
bool check(int l,int r){
	long long x=0;
	for(int i=1;i<=ans;i++){
		if(l==c1[i]||r==c2[i]||r==c1[i]||l==c2[i]){
			return false;
		}
		if(l<=c1[i]&&r>=c1[i]){
			return false;
		}
	}
	int da=ans;
	for(int i=l;i<=r;i++){
		x=x^a[i];
	}
	if(x==k){
		ans++;
		c1[ans]=l;
		c2[ans]=r;
	//	cout<<l<<" "<<r<<endl;
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("xor.in ","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
		//	cout<<a[i]<<endl;
			ans++;
			c1[ans]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			check(i,j);
		}
	}
	cout<<ans;
	return 0;
}
