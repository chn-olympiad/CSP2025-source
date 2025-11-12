 #include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int vis[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt = 0;
	string s;
	cin>>s;
	for(int i = 0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			vis[cnt] = s[i]-'0';
			cnt++;
		}
	} 
	sort(vis,vis+cnt,cmp);
	for(int i = 0;i<cnt;i++){
		cout<<vis[i];
	}
	return 0;
}
