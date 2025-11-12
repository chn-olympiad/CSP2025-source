#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N]={0};
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	int z=0,ans=0;
	for(int i=1;i<=n;i++){
		int x=b[i]^b[z];
		if(x==k){
			z=i;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}