#include <bits/stdc++.h>
using namespace std;
const int MAX_N=500010;
int n;
long long ans=0;
long long a[MAX_N],s[MAX_N],k;
long long f[MAX_N];
bool fB=1;
int check(int x,int y){
	if((s[y]^s[x-1])==k) return 1;
	else return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		if(a[i]>1) fB=0;
	}
	if(fB){
		if(k==1){
			for(int i=1;i<=n;i++) if(a[i]==1) ans++;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else{
					if(a[i]==a[i+1]){
						ans++;
						i++;
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			f[i]=max(f[i],f[j]+check(j+1,i));
		}
	}
	cout<<f[n];
	return 0;
}