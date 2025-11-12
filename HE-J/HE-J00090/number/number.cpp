#include<bits/stdc++.h>
using namespace std;
long long s[100005];
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		if (n==1){
			cout<<" ";
		}else{
			cout<<s;
		}
	}
	cout<<s;
	return 0;
} 
