#include<bits/stdc++.h> 
using namespace std;
int n,k,a[500100],ans;
bool b[500100];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			b[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i])continue;
		int x=a[i];
		for(int j=i+1;j<=n;j++){
			x=(x^a[j]);
			if(b[j])break;
			if(x==k){
				ans++;
				for(int k=i;k<=j;k++)b[k]=1;
				break;
			}
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
