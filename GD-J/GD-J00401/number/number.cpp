#include<bits/stdc++.h>
using namespace std;
int t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(char c:s)if(c>='0'&&c<='9')t[c-'0']++;
	for(int i=9;i>=0;i--)while(t[i]--)cout<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
