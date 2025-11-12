#include<bits/stdc++.h>
using namespace std;
string s;
int l,c=1,a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[c]=s[i]-'0';
			c++;
		}
	}
	sort(a+1,a+c);
	for(int i=c-1;i>=1;i--) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
