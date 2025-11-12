#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[1000005];
	int n=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i];
			n++;
		}
		
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)cout<<a[i];
}
