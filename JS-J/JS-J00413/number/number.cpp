#include<bits/stdc++.h>
using namespace std;
string a[1000009];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=0,j=1;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i];
			n++;
			j++;
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)cout<<a[i];
	return 0;
}
