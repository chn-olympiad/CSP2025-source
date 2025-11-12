#include<bits/stdc++.h>
using namespace std;
string s;int j[10]; 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;int l=s.length();
	for(int i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9')
			j[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(j[i]--)cout<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
