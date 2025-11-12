#include<bits/stdc++.h>
using namespace std;
int a[100],maxn=-1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;
			maxn=max(maxn,s[i]-'0');
		}
	}
	if(maxn==0){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++)
			cout<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
