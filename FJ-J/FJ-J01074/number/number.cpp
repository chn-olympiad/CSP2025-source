#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string a;
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.length();i++){
		int x=(int)a[i]-48;
		if(int(a[i])>57 || int(a[i])<48) continue;
		num[x]++;
	}
	for(int i=9;i>=0;i--){
		if(num[i]==-1) continue;
		for(int j=1;j<=num[i];j++) cout<<i;
	}
	return 0;
}