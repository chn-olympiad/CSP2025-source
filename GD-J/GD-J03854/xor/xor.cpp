#include<bits/stdc++.h>
using namespace std;
int n,k,h[500100],s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	if(k<=1){
		for(int i=1;i<=n;i++){
			cin>>h[i];
			if(h[i]==k){
				s++;
			}
		}
		cout<<s;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			cin>>h[i];
		}
		for(int i=1;i<=n;i++){
			if(h[i]==k){
				s++;
			}else{
				long long f=h[i];
				for(int j=i+1;j<=n;j++){
					f^=h[j];
					if(f==k){
						i=j+1;
						s++;
						break;
					}
				}
			}
		}
		cout<<s;
	} 
	return 0;
} 
