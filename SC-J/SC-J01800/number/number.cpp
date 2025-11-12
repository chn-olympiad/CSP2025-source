#include<bits/stdc++.h>
using namespace std;
string s;
int n=0,a[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0' and s[i]<='9'){
			n+=1;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1);
	if(a[n]==0){
		cout<<0;
	}
	else{
		for(int i=n;i>=1;i--){
			cout<<a[i];
		}
	}
	return 0;
} 