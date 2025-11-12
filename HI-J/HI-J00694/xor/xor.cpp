#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1 && a[1]!=k){
		cout<<0;
		return 0;
	} 
	if(n==1 && a[1]==k){
		cout<<1;
		return 0;
	} 
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			a[i]=-1;
		}
	}
	int b=0;
	for(int i=1;i<=n;i++){
		if(a[i]==-1) continue;
		else b=a[i];
		for(int j=i+1;j<=n;j++){
			if(a[j]==-1){
				b=0;
				i+=j;
				break;
			}
			b=(b^a[j]);
			if(b==k){
				b=0,ans++;
				i+=j;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
