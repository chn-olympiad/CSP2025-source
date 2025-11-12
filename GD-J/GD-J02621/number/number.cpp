#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int cmp(int l,int r){
	return r<l;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
	cin>>s;
	int len=s.size();
	int cnt=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt++]=s[i]-'0';
		}
	}
	sort(a+0,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		if(a[i]>=0&&a[i]<=9){
			cout<<a[i];
		}
	}
	return 0;
}
