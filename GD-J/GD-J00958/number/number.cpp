#include<bits/stdc++.h>
using namespace std;
string s;
int n,nu[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;
			nu[n]=s[i]-'0';
		}
	}
	sort(nu+1,nu+n+1);
	for(int i=n;i>=1;i--){
		cout<<nu[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
