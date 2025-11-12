#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int dis;
int f[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	IOS;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;++i){
		if('0'<=s[i] && s[i]<='9'){
			f[++dis]=s[i]-'0';
		}
	}
	sort(f+1,f+dis+1,cmp);
	for(int i=1;i<=dis;++i){
		cout<<f[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 