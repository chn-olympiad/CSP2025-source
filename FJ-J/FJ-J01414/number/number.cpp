#include <bits/stdc++.h>
using namespace std;
string s[100000];
int cnt,a[100000];
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
		for(int i=1;i<=10000;i++){
			cin>>s[i];
		if(s[i]==1||s[i]==2||s[i]==3||s[i]==4||s[i]==5||s[i]==6||s[i]==7||s[i]==8||s[i]==9||s[i]==0){
			cin>>a[i];
			cnt++;
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=1;i<=10000;i++){
		cout<<s[i];
	}
	return 0;
}
