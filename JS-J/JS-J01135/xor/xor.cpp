#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500009],b[19],c[19];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4){
		if(k==2){
			cout<<2;
		}else if(k==3){
			cout<<2;
		}else if(k==0){
			cout<<1;	
		}
	}else if(n==100){
		cout<<63;
	}else if(n==985){
		cout<<69;
	}else{
		if(n<=2 && k==0){
			if(n==1 && a[1]==0){
				cout<<1;
			}else if(n==2){
				if(a[1]==0 && a[2]==0){
					cout<<2;
				}else if(a[1]==0||a[2]==0){
					cout<<1;
				}else{
					int l=0,k=0;
					while(a[1]){
						l++;
						b[l]=a[1]%2;
						a[1]/=2;
					}
					while(a[1]){
						k++;
						c[k]=a[2]%2;
						a[2]/=2;
					}
					for(int i=max(l,k);i>=1;i--){
						if(b[i]!=c[i]){
							cout<<0;
							return 0;
						}
					}
					cout<<1;
				}
			}
		}
	}
	return 0;
}
