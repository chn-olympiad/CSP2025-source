#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char a[N];
string s;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=N;i++){
		cin>>a[i];
		if(a[i]!='1' or a[i]!='2' or a[i]!='3' or a[i]!='4' or a[i]!='5' or a[i]!='6' or a[i]!='7' or a[i]!='8' or a[i]!='9' or a[i]!='0'){
			a[i]=' ';
		}
	}
	sort(a+1,a+N,cmp);
	for(int i=1;i<=N;i++){
		cout<<a[i];
	}
	return 0;
}
