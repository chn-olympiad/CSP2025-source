#include <bits/stdc++.h>
using namespace std;
string s;
int k;
char a[100005];
bool cmp(char a,char b){
	if(a!=b) return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<=s.length(); i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i];
			k++;
		}
	}
	sort(a,a+k,cmp);
	for(int i=0; i<=k; i++){
		cout<<a[i];
	}
	return 0;
}
