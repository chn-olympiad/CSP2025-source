#include<bits/stdc++.h>
#define ll long long

using namespace std;
int T;
int a[15];
int read(){
	int sgn=0,ret=0;
	char chr=getchar();
	while (!isdigit(chr)) sgn|=chr=='-',chr=getchar();
	while (isdigit(chr)) {
	ret=ret*10+chr-'0',chr=getchar();}
	return sgn ? -ret:ret;
}
void solve(){
	string str;
	bool can;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9') a[str[i]-'0']++,can=true;
	} 
//	for (int i=0;i<10;i++){
//		cout<<a[i]<<" ";
//	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++) cout<<i;
	}
	if(!can) cout<<"0";
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=1;
	for (int t=0;t<T;t++) solve();
	return 0;
}

 
