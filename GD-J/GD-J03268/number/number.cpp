#include<bits/stdc++.h>
using namespace std;
string s="";
short a[1000005];
int num=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[i]=s[i]-'0';
			num++;
		}
	}
	sort(a,a+s.size());
	int n=num;
		for(int i=s.size()-1;i>=s.size()-num;i--){
		cout<<a[i];
		n--;
		if(n==0){
			break;
		}
	}
	return 0;
 } 
