#include<bits/stdc++.h>
using namespace std;
int t[1005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		t[(int)s[i]]++;
	}
	for(int j='9';j>='0';j--){
		for(int i=1;i<=t[j];i++)printf("%c",j);
	}
	return 0;
}
