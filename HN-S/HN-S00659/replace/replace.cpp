#include<bits/stdc++.h>
using namespace std;
int n,q,z[200005],k;
string a[200005],b[200005],s[200005];
long long ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=2;i<=n*2;i+=2){
		cin>>s[i]>>s[i-1];
	}
	while(q--){
		ans=0;
		k++;
		for(int i=1;i<=200005;i++){
			z[i]=0;
		}
		for(int i=1;i<=a[k].size();i++){
			if(a[k][i]!=b[k][i])z[k]++;
		}
		for(int i=1;i<=n*2;i++){
			if(b[k]==s[i]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
