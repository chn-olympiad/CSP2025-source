#include<bits/stdc++.h>
using namespace std;
string a;
int num[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if('0'<=a[i]&&a[i]<='9') num[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++) cout<<i;
	}
	return 0;
}