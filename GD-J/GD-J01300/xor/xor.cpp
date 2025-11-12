#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k,a[maxn],b[maxn],s;
bool f[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((i+j)<=n){
				int t=b[i+j]^b[j-1];
				for(int l=j;l<=j+i;l++){
					if(f[l]){
						t=-1;
						break;
					}
				}
				if(t==k){
					s++;
					for(int l=j;l<=j+i;l++){
						f[l]=1;
					}
				}
			}
		}
	}
	cout<<s;
	
	return 0;
}
