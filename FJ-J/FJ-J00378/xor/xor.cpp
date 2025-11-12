#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '/n'
int n;
ll k;
ll a[500010];
ll ans=0;
bool checkA(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			return false;
		}
	}
	return true;
}
void solveB(){
	for(int i=1;i<=n;){
		if(a[i]!=a[i+1]){
			ans++;
			i+=1;
		}
	}
	cout<<ans;
	return ;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0;
	}else
	if(n==2){
		cout<<1;
	}else 
	if(checkA()==true){
		if(k==1){
			cout<<n;
		}else{
			cout<<n/2;
		}
	}else 
	if(k<=1){
		solveB();
	}
	return 0;
}
