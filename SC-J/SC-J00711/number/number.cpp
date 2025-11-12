#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int maxn=1e6+5;
string s;
char a[maxn];
bool cmp(char x,char y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	s=' '+s;
	int l=s.size(),mx=1;
	for(int i=1;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[mx++]=s[i];
		}
	}
	mx--;
	sort(a+1,a+mx+1,cmp);
	for(int i=1;i<=mx;i++){
		cout<<a[i];
	}

	return 0;
}