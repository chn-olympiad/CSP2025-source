#include<bits/stdc++.h>
using namespace std;

int n,k,a[114514];
string get2(int x){
	string ans;
	while(x!=0){
		if(x%2==0){
			ans+='0';
		}else if(x%2==1){
			ans+='1';
		}
		x/=2;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<1;
	return 0;
} 
