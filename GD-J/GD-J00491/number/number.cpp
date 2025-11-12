#include<bits/stdc++.h>
#define int long long
using namespace std;
string x;
int a[100];
bool f;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	for(int i=0;i<x.length();i++){
		if(x[i]>='0'&&x[i]<='9'){
			a[x[i]-'0']++;	
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]&&i!=0)f=1;
		if(i==0&&!f){
			cout<<0;
			return 0;
		}
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}

