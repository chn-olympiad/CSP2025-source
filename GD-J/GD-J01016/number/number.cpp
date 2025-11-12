#include<bits/stdc++.h> 
using namespace std;
string a;
bool isnum(char x)
{
	if(x>='0'&&x<='9')
		return true;
	return false;
}
int ans[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>a;
	for(int i=0;i<a.size();i++)
		if(isnum(a[i]))
			ans[(a[i]-'0')]++;
	for(int i=9;i>=0;i--)
		while(ans[i])
			cout<<i,ans[i]--;
	return 0;
}
