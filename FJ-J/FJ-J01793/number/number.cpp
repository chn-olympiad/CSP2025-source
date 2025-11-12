#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int read();
string s;
int a[20];
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++) {
		if(s[i]>='0' && s[i]<='9') {
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--) {
		for(int j=1;j<=a[i];j++) {
			cout<<i;
		}
	}
	return 0;
}
int read(){
	int Ca=0;char Cr=' ';int Cf=1;
	while(Cr<'0' || Cr>'9') {Cr=getchar();if(Cr=='-'){Cf=-1;}}
	while(Cr>='0' && Cr<='9') {Ca=Ca*10+Cr-48;Cr=getchar();}
	return Ca*Cf;
}
