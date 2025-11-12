#include<bits/stdc++.h>
#define int long long
using namespace std;
string str;int stri[1000005],cnt;
bool cmp(int a,int b){return a>b;}
signed main(){
	ios::sync_with_stdio;cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]>='0'&&str[i]<='9'){
			stri[i]=str[i]-'0';
			cnt++;
		}
	}
	sort(stri,stri+str.length(),cmp);
	for(int i=0;i<cnt;i++){
		cout<<stri[i];
	}
	return 0;
} 
