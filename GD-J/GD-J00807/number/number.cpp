#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
const int maxn=1e6+5;
string s;
int a[maxn],k;
bool lg=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0' && s[i]<='9'){
			a[k]=int(s[i]-'0');
			if(a[k]!=0)lg=0;
			k++;
		}
	}
	if(lg){
		cout<<0;
		return 0;
	}
	sort(a,a+k,cmp);
	for(int i=0;i<k;i++)printf("%d",a[i]);
	return 0;
}
