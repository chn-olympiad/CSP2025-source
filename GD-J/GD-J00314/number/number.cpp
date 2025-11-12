#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[1000100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')
		{
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--)
		cout<<a[i];
	return 0;
}
