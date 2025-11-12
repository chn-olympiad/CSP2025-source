#include<bits/stdc++.h>
using namespace std;
string s; 
const int N=1e6+5;
char a[N]; 
int num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'){
			a[i]=s[i];
		}
	}
	for(int i=0;i<s.size();i++){
		cout<<a[i];
	}
	return 0;
}
