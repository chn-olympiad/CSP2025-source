#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
string s;
char a[MAXN];
int lena;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++lena]=s[i];
		}
	}
	sort(a+1,a+lena+1,cmp);
	for(int i=1;i<=lena;i++){
		cout<<a[i];
	}
	return 0;
}
