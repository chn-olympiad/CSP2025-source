#include<bits/stdc++.h>
using namespace std;
int tong[15];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			tong[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)for(int j=1;j<=tong[i];j++)cout<<i;
	return 0;
}

