#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000005],sumn;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=0;
	for(int i=0;i<s.length();i++){
		if(s[i]<='9'&&s[i]>='0'){
			n[j++]=s[i]-'0';
			sumn++;
		}
	}
	sort(n,n+sumn);
	for(int i=sumn-1;i>=0;i--)cout<<n[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

