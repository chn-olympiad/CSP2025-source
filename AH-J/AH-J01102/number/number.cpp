#include<bits/stdc++.h>
using namespace std;
int a[1000010],t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>=48&&s[i]<=57){
			a[t]=s[i]-48;
			t++;
		}
	}
	sort(a,a+t);
	for(int i=t-1;i>=0;i--)cout<<a[i];
	return 0;
}
