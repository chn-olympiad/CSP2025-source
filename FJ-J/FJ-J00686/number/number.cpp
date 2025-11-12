#include<bits/stdc++.h>
using namespace std;
string s;
int i,m;
char a[110000],n[110000];
bool cmp(char x1,char x2){
	return x1-'0'>x2-'0';
}
int main(){
	freopen("number.in ","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<=s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			m++;
			a[m]=s[i];
		}
	}
	sort(a,a+m+1,cmp);
	for(int j=0;j<=m;j++){
		n[j]=a[j];
	}
	cout<<n;
	return 0;
}
