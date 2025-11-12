#include<bits/stdc++.h>
using namespace std;
int a[1000009];
int main()
{
	int b=1;
	string s;
	freopen("number.in","r",stdin);
	freopen("numner.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b]=s[i]-'0';
			b++;
		}
		else continue;
	}
	for(int i=0;i<b;i++){
		for(int j=2;j<b;j++){
			if(a[j]>a[j-1]){
				int g;
				g=a[j];
				a[j]=a[j-1];
				a[j-1]=g;
			}
		}
	}
	for(int i=1;i<b;i++)cout<<a[i];
	return 0;
}
