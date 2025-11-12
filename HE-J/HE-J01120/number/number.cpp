#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int o=0;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])==true){
			o++;
			a[o]=s[i]-'0';
		}
	}
	sort(a+1,a+o+1,cmp);
	for(int i=1;i<=o;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
