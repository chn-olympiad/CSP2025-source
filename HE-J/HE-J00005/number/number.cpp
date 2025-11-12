#include <bits/stdc++.h>
using namespace std;
string s,k;
int a[100010];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			k=k+s[i];
		}
	}
	for(int i=0;i<=k.size()-1;i++){
		a[i]=k[i]-'0';
	}
	sort(a,a+k.size(),cmp);
	for(int i=0;i<=k.size()-1;i++){
		cout<<a[i];
	}

	return 0;
}
