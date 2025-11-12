#include<bits/stdc++.h>
using namespace std;
int a[1000010],j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int s1=s.size();
	for(int i=0;i<s1;i++)
		if(s[i]>='0'&&s[i]<='9'){
			j++;
			a[j]=s[i]-'0';
		}
	sort(a+1,a+1+j);
	for(int i=j;i>=1;i--) cout<<a[i]; 
	return 0;
}

