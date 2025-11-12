#include <bits/stdc++.h>
using namespace std;
string s;
int numbrs[1000006],o=1;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		s[i]-='0';
		if(s[i]>=0&&s[i]<=9){
			numbrs[o]=s[i];
			o++;
		}
	}
	o--;
	sort(numbrs+1,numbrs+1+o,cmp);
	for(int i=1;i<=o;i++){
		cout<<numbrs[i];
	}
	return 0;
}
