#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string str;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	cin>>str;
	int cnt=0;
	for(int i=0;i<str.length();i++){
		if('0'<=str[i]&&str[i]<='9'){
			a[++cnt]=str[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,cmp);
	if(a[1]==0) cout<<0;
	else{
		for(int i=1;i<=cnt;i++){
			cout<<a[i];
		}
	}
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve();
	return 0;
}

