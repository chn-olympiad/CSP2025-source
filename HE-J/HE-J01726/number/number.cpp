#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int a[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a+0,a+n);
	for(int i=n-1;i>=0;i--){
		if(a[n-1]==0){
			cout<<0<<endl;
			break;
		}
		cout<<a[i];
	}
	return 0;
} 
