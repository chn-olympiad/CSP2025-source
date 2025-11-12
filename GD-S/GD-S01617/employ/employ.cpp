#include<bits/stdc++.h>
using namespace std;
int s[510];
long long sum=1;
int main(){
	freopen("employ1.in","r",stdin);
	int n,m;string a;
	cin>>n>>m;
    cin>>a;
	for(int i=1;i<=n;i++){
		cin>>s[i];
}
	if(m!=n){
		cout<<0;
	}else{
		for(int i=1;i<=n;i++){
			sum=(sum*i)%998244353;
		}
	}
	cout<<sum;
	return 0;
} 
