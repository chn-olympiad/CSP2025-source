#include<bits/stdc++.h>
using namespace std;
int n,k,ans,x;
int a[500005];
bool f;
void solve0(){
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			ans++;
			continue;
		}
		if(a[i]==a[i+1]){
			i+=1;
			ans++;
		}
	}
	cout<<ans;
}
void solve1(){
	for(int i=1;i<=n;i++){
		if(a[i]==1) ans++;
	}
	cout<<ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) f=1;
	}
	if(f==0){
		if(k==0) solve0();
		if(k==1) solve1();
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j==i+1){
				x=(a[i]^a[j]);
			}else{
				x=(x^a[j]);
			}
			if(x==k){
				i=j+1;
				ans++;	
			}
		}
	}
	cout<<ans;
	return 0;
}
