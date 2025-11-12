#include<bits/stdc++.h>
using namespace std;
char s[1000000];
int a[1000000],cnt;
bool f;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=strlen(s);
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[cnt++]=s[i]-'0';
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		if(a[i]==0 && f==0){
			continue;
		}else{
			cout<<a[i];
			f=1;
		}
	}
	if(f==0) cout<<0;
	return 0;
}
