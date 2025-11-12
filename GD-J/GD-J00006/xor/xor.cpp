#include<bits/stdc++.h>
#define L long long
using namespace std;
const int N=2*1e5+10;
L n,k;
L a[N];
L ans;
//14 0
//1 1 1 1 1 1 1 1 1 1 1 1 1 1

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f1=1,f2=1;
	for(L i=0;i<n;i++){
		cin>>a[i];if(a[i]!=1)f1=0;
		if(a[i]>1)f2=0;
	}
	if(f1){
		if(n%2==1){
			cout<<0;return 0;
		}else cout<<n/2;
	}else if(f2){
		if(k==0){
			L ans=0;
			for(L i=0;i<n;i++){
				if(a[i]==1){
					while(a[++i]==0){
						if(i==n){
							cout<<0;return 0;
						}
					}
					ans++;
				}if(a[i]==0)ans++;
			}cout<<ans;
		}else if(k==1){
			L ans=0;
			L i=0;
			while(i<n){
				if(a[i]==0){
					while(a[i++]==0){
						if(i==n){
							cout<<0;return 0;
						}
					}ans++;continue;
				}
				else{
					ans++;
				}i++;
			}
			cout<<ans;
		}else cout<<0;
	}
	return 0;
}

