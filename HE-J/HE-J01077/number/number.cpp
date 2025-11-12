#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,b,c;
	cin>>s;
	long long a=s.size(),f=0,t[100005];
	for(int i=0;i<a;i++){
		if(s[i]>='0' && s[i]<='9') b[f++]=s[i];
	}
	if(f==1) cout<<b[0];
	else{
		for(int i=0;i<f;i++) t[i]=b[i]-'0';
	}
	sort(t,t+f);
	for(int i=f-1;i>=0;i--) cout<<t[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
