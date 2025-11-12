#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int num1=0,num0=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1)num1++;
		else num0++;
	}
	if(n<=2){
		cout<<num1/2;
		return 0;
	}
		if(k==1){
			cout<<num1;
			return 0;
		}else if(k==0){
			cout<<num0+num1/2;
			return 0;
		}
	
	
		return 0;
}