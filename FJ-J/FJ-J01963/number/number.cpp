#include<bits/stdc++.h>
using namespace std;
string s;
int k;
char a[10]={'0','1','2','3','4','5','6','7','8','9'};
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int k=0;k<=s.size();k++){
		for(int i=0;i<=9;i++){
			if(s[k]==a[i])  num[i]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int k=1;k<=num[i];k++)  cout<<i;
	}
	return 0;
}

