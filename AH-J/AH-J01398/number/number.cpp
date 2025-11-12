#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[10000]={-1};
	cin>>s;
	for(int i=0;i<s.size();i++){
	if(s[i]-48<=9){
	a[i]=s[i]-48;
	}
	}
	sort(a,a+1);
	for(int i=0;i<s.size();i++){
		cout<<a[i];
		if(a[i]==-1){
			break;
		}
	}
return 0;

}
