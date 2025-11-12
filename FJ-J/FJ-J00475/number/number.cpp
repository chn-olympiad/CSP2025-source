#include<bits/stdc++.h>
using namespace std;
string s;
int a[10005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int lenss=s.size();
	for(int i=0;i<lenss;i++){
		a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++)cout<<i;
		}
	}
	return 0;
}
