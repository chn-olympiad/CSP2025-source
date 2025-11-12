#include<bits/stdc++.h>
using namespace std;
int f[1100000],n;
string s;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] and s[i]<='9'){
			f[++n]=s[i]-'0';
		} 
	}
	sort(f+1,f+1+n,cmp);
	for(int i=1;i<=n;i++){
		cout<<f[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
