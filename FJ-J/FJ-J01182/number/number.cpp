#include<bits/stdc++.h>
using namespace std;
string s;
int l,a[16];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	l=s.size();
	for(int i=0;i<l;i++){
		if(isdigit(s[i])){
			a[int(s[i]-'0')]++;
		}
	}
	int i=9;
	while(i>=0){
		if(a[i]>0){
			cout<<i;
			a[i]--;
		}
		else{
			i--;
		}
	}
	return 0;
}

