#include<bits/stdc++.h>
using namespace std;
const int INF=1e6+10;
int a[INF]={0};
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cnt=0,rnt=0;
	for(int i = 0 ; i < s.length();i++){
		if(s[i]<='9'&&s[i]>='1'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
		if(s[i]=='0'){
			rnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i = 0 ; i < cnt;i++){
		cout<<a[i];
	}
	for(int i=0;i<rnt;i++){
		cout<<0;
	}
	return 0;
}


