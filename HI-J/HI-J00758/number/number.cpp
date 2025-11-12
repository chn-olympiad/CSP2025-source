#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char a[s.size()+5];
	int cnt=s.size();
	for(int i=0;i<=s.size();i++)
	{
		a[i]=s[i];
	}
	sort(a+0,a+cnt);
	
	for(int i=cnt;i>=0;i--)
	{
		if(a[i]>='0'&&a[i]<='9') cout<<a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

