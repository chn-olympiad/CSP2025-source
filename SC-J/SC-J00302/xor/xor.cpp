#include "bits/stdc++.h"
using namespace std;
const int N=5e5+10;
int a[N];

int main(){
	cin.tie(nullptr);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int t=a[1];

	for(int i=1;i<=n;i++){
		if(a[i]==k){
			cnt++;
			continue;
		}
		if(i+1<=n){
			if((t xor a[i+1])==k){
				cnt++;
				if((i+2)<=n){
					t=a[i+2];
					continue;
				}else{
					break;
				}
			}else{
				t=(t xor a[i+1]);
				continue;
			}
		}
	}
	
	cout<<cnt;
	return 0;
} 