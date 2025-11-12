#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k=1; 
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[k]=int(s[i]-'0');
			k++;
		}
	}
	k--;
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}
	return 0;
 } 
