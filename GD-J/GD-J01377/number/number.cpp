#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long bag[10]={0,0,0,0,0,0,0,0,0,0};
	for(int i=0;i<a.length();i++)
	{
		if(a[i]<='9'&&a[i]>='0'){
			bag[int(a[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<bag[i];j++){
			cout<<i;
		}
	}
	return 0;	
} 
