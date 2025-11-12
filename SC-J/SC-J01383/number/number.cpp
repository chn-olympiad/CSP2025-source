#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+1;
string str;
int CSP[MAXN],RP;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	RP=0;
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]>=48&&str[i]<=57){
			CSP[RP]=str[i]-48;
			RP++; 
		}
	}
	sort(CSP,CSP+RP,cmp);
	for(int i=0;i<RP;i++){
		cout<<CSP[i];
	}
	return 0;
}
//试题册密码：上善若水 
//神圣的CCF大人给点分吧 
// ___          _       _   __     ___   _____    ___
//|   |        / \     | | / /    |   | / ___ \  |   |
// | |        / _ \    | |/ /      | |  | |  | |  | |
// | |       / /_\ \   |   /       | |  | |  | |  | |
// | |      / _____ \  |   \       | |  | |  | |  | |
// | |     / /     \ \ | |\ \      | |  | |__| |  | |
//|___|   /_/       \_\|_| \_\    |___| \_____/  |___|