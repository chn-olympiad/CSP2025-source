//I Love CCF 
//Accepted!
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define down(i,x,y) for(int i=(x);i>=(y);--i)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
using namespace std;
char s[1000006];
vector<char> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,1,n){
		if(s[i]>='0'&&s[i]<='9'){
			v.eb(s[i]);
		}
	}
	sort(v.begin(),v.end(),greater<char>());
	for(char i:v){
		printf("%c",i);
	}
	return 0;
}
//nlogn
//I Love CCF
