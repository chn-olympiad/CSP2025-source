#include<bits/stdc++.h>
using namespace std;
string s;
int l[10];
int main(){
	freopen("number.in",r,stdin);
	freopen("number.out",w,stdout);
	cin>>s;
	for(int i=0;i<=9;i++) l[i]=0;
	for(int i=0;s[i]!='\0';i++){
		if (int(s[i])>=48 and int(s[i])<=57) l[int(s[i])-48]++;
	} 
	for (int i=9;i>=0;i--){
		for(int j=i;l[j]>0;l[j]--){
			cout<<i;
		}
	}

	return 0;
}

