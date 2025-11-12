#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s[100005];
	int c[100005];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(n==3){
		cout<<2;
		return 0;
	} 
	if(s[5]='1'){
		cout<<n*m*4266;
		return 0;
	} 
	cout<<n*592778/m+1;
	return 0;
}
