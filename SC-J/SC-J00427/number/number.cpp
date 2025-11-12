#include<bits/stdc++.h>

using namespace std;

bool cmp(int x,int y){
	return x>y;
}

const int maxn=1e6+10;
string s;
int a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length(),p=1; 
	for(int i=0;i<len;++i){
		if(s[i]>='0'&&s[i]<='9'){
			a[p]=s[i]-'0';
			++p;
		}
	}
	sort(a+1,a+p+1,cmp);
	bool tmp=1;
	for(int i=0;i<p;++i){
		if(a[i]!=0) tmp=0;
	} 
	if(tmp==1){
		cout<<"0";
		return 0;
	}
	else for(int i=1;i<=p;++i) printf("%d",a[i]);
	return 0;
}