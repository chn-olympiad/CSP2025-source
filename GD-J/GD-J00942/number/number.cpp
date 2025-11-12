#include<bits/stdc++.h>
using namespace std;
string S;
int cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>S;
	for(int i=0;i<S.size();i++)
		if('0'<=S[i]&&S[i]<='9')
			cnt[S[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(cnt[i]--) cout<<i;
	return 0;
}
/*
9178
9871

aaaaa1

aabaa01
*/
