#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in ","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=0,a=0,num[1000005];
	for(int i=1;i<=s.size();i++){
		if (s[i]==1 && s[i]==2 && s[i]==3 && s[i]==4 && s[i]==5 && s[i]==6 && s[i]==7 && s[i]==8 && s[i]==9){
			num[i]=s[1];
			a++;
		}
	}
	for(int i=1;i<=a;i++){
		if(num[i]<num[i+1]){
			n=num[i];
			num[i]=num[i+1];
			num[i+1]=n;
		}
	}
	for(int i=1;i<=a;i++){
		cout<<num[i];
	}
	return 0;
}
