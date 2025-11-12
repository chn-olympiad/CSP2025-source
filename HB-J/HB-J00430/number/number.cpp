#include <bits/stdc++.h>
using namespace std;
string a;
int t[15];
int main()
{
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>a;
	for(int i=0;i<=a.size()-1;i++){
		if(a[i]>='0'&&a[i]<='9')t[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=t[i];j>=1;j--){
			cout<<i;
		}
	}
	return 0;		
}	
	
