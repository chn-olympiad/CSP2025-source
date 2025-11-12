#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
string str;
int a[1000010];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>str;
	int num=0;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			a[++num]=str[i]-'0';
		}
	}
	sort(a+1,a+num+1);
	for(int i=num;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
