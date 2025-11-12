#include<bits/stdc++.h>
using namespace std;
string s;
int d=1,len;
bool f=0;
char a[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0')a[d++]=s[i];
	}
	sort(a+1,a+d+1,cmp);
	for(int i=1;i<=d;i++){
		if(a[i]<='9'&&a[i]>='0'&&a[i]!='0'){
			f=1;
			break;
		}
	}
	if(f){
		for(int i=1;i<=d;i++)cout<<a[i];
	}
	else cout<<"0";
	return 0;
}
