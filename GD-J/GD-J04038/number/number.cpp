#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("numder.in","r",stdin);
	freopen("numder.out","w",stdout);
	string s;
	int a[10000],p=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			a[p]=s[i]-'0';
			p++;
		}
	}
	sort(a,a+p,cmp);
	for(int i=0;i<p;i++){
		cout<<a[i];
	}
	return 0;
}
