#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string s;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		//cout<<int(s[i])-48<<" ";
		if(s[i]>='0'&&s[i]<='9') a[int(s[i])-48]++;
	}	
	for(int i=9;i>=0;i--){
		if(!a[i]) continue;
		for(int j=1;j<=a[i];j++) cout<<i;
	}
	return 0;
}
