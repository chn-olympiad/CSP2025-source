#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,-1,sizeof(a));
	cin>>s;
	long long n=s.size();
	for(int i=0;i<s.size();i++){
		if(int(s[i])-48>=0&&int(s[i])-48<=9){
			a[i]=int(s[i])-48;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<s.size();i++){
		if(a[i]==-1){
			cout<<"\n";
			break;
		}
		cout<<a[i];
	}
	return 0;
}