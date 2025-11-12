#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,tt=0,a[501];
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(s[i]=='1'){
			tt++;
		}
	}
	if(m>tt){
		cout<<"0";
		return 0;
	}else if(m==tt){
		cout<<"1";
		return 0;
	}
	return 0;
}
/*
3 2
101
1 1 2
*/
