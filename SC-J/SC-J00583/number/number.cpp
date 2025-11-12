#include<bits/stdc++.h> 
using namespace std;
int qq[10];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')qq[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=qq[i];j++)cout<<i;
	}
	return 0; 
}