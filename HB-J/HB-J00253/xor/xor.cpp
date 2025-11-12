#include<bits/stdc++.h>
using namespace std;
int a;
int s[1000005],n,ans,m,l,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=l;i<=n;i++){
		a=0;
		k=0;
		for(int j=l;j<=n;j++){
			cout<<a<<"  "<<s[j]<<' ';
		    if(a+s[j]>m){
				if (k>0){cout<<endl;
				ans++;
				l=j;}
				break;
	        }
	        else {a+=s[j];k++;}
	}}
	if(ans>0)ans++;
	cout<<ans;
    return 0;
}
