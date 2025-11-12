#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e6+6;
string s;
bool cmp(int a,int b){return a>b;}
int a[N],len;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(size_t i=0;i<s.size();i++){
		if(s[i]=='0')a[++len]=0;
		if(s[i]=='1')a[++len]=1;
		if(s[i]=='2')a[++len]=2;
		if(s[i]=='3')a[++len]=3;
		if(s[i]=='4')a[++len]=4;
		if(s[i]=='5')a[++len]=5;
		if(s[i]=='6')a[++len]=6;
		if(s[i]=='7')a[++len]=7;
		if(s[i]=='8')a[++len]=8;
		if(s[i]=='9')a[++len]=9;
	}
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++){
		cout<<a[i];
	}
	return 0;
}
/*
5

5
*/
/*
290es1q0

92100
*/
