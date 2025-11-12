#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,cnt;
bool f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			f=true;
		}else{
			if(f){
				cnt=a[i];
				f=false;
			}else{
				cnt^=a[i];
				if(cnt==k){
					ans++;
					f=true;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
