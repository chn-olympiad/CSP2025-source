#include<bits/stdc++.h>
using namespace std;
string a;
char s[1000020];
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int idx=1;
	for(char i='9';i>='0';i-=1){
		for(int j=1;j<=a.size();j++){
			if(a[j]==i){
				cout<<i;
			}
		}
	}
	return 0;
}
