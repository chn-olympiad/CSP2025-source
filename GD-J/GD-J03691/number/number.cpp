#include<bits/stdc++.h>
using namespace std;
int b[110];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	for(auto it:str) if(it>='0'&&it<='9') b[it-'0']++;
	for(int i=9;i>=0;i--) while(b[i]--) printf("%d",i);
	return 0;
}
