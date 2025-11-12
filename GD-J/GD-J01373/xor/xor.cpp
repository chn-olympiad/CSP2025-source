#include<bits/stdc++.h>
using namespace std;

const int N=1e7+10;
int n,k,ans;
int a[N],f[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		int x=a[l];
		for(int r=l;r<=n;r++){
			int z=0;
			for(int i=l;i<=r;i++){
				if(f[i]==1){
					x=a[l];
					z=1;
					break;
				}
				x=(x|a[i]);
			}
			if(x==k and z==0){
				ans++;
				for(int i=l;i<=r;i++){
					f[i]=1;
				}
			}
			x=a[l];
			z=0;
		}
	}
	cout<<ans;
	return 0;
}
