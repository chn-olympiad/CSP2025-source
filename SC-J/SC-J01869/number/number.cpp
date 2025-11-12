#include<bits/stdc++.h>
using namespace std;
string s;
int a[(int)(1e6+1)],cnt,b[101],flag=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if((s[i]<='9')&&(s[i]>='0')){
			a[++cnt]=s[i]-'0';
		}
	}
	for(int i=1;i<=cnt;i++){
		b[a[i]]++;
		if(a[i])flag=1;
	}
	if(flag==0){
		cout<<0;
	}else{
		for(int i=9;i>=0;i--){
			for(int j=1;j<=b[i];j++){
				cout<<i;
			}
		} 
	}
	return 0;
}