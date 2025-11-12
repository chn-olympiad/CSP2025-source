#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500010];

long long ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
		cin>>a[i];
    }
	if(k%2==1){
		for(int i=0;i<n;i++){
			if(a[i]%2==1){
				ans++;
			}
		}
	}else if(k%2==0&&k!=0){
		for(int i=0;i<n;i++){
			if(a[i]%2==0){
				ans++;
			}
		}
	}else if(k==0){
		for(int i=0;i<n;i++){
			if(a[i]==0){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

