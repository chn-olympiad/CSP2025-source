#include<bits/stdc++.h>
using namespace std;
string s;
int sz[1000005];
int cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int size=s.length();
	for(int i=0;i<=size;i++){
		char s1=s[i];
		if('0'<=s1&&s1<='9'){
			sz[cnt++]=int(s1-'0');
		}
	}
	sort(sz,sz+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<sz[i];
	}
	return 0;
}
