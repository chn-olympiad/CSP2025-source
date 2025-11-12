#include <iostream>
#include <cstdio> 
using namespace std;

const int MAXN = 5e5+5;

int n,k;
int a[MAXN];
int xros[MAXN];
int tmp,ans;
int lj = 0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		xros[i] = xros[i-1]^a[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = lj;j<i;j++){
			if((xros[i]^xros[j])==k){
				ans++;
				j = i;
				lj = i;
			}
		}
	}
	cout<<ans;
	return 0;
}
