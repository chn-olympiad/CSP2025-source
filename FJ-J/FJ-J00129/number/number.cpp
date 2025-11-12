#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	cin>>s;
	int t=0;
	for(int i=0;i<s.size();i++){
		if(int(s[i])>=48&&int(s[i])<=57){
			a[t]=int(s[i])-48;
			t++;
		}
	}
	sort(a,a+t);
	for(int i=t-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
