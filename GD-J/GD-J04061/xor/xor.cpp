#include <bits/stdc++.h>
using namespace std;
long long n,k,a[6000000],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int i=0;i<n;++i){
		long long mod=a[i];
		if(mod==k){
			++ans;
		}else{
			for(int j=i+1;j<n;++j){
				mod=mod^a[j];
				if(mod==k){
					++ans;
					i=j;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
