#include<bits/stdc++.h>
using namespace std;
int l=0;
string s;
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","W",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int a=s[i];
		if(a>=48 && a<=57){
			b[l]=a-48;
			l++;
		}
	}
	sort(b,b+l);
	for(int i=l-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
} 
