#include<bits/stdc++.h>
using namespace std;
string s;
int w[101];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	for(int i=0;i<(int)s.size();i++)if(48<=s[i]&&s[i]<=57)w[s[i]-48]++;
	for(int i=9;i>=0;i--)while(w[i]--)cout<<i;
} 
