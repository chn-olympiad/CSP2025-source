#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	char s[505];
	cin>>s;
	if(m==n){
		cout<<1;
		return 0;
	}
	long long op=1;
	long long o=1;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			op=(op*o)%998244353;
			o++;
		}
	}
	cout<<op; 
	return 0;
} 
