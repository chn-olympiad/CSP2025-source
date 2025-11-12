#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0' && s[i]<='9'){
			a[i]=int(s[i]);
		}else{
			a[i]=-1;
		}
	}
	
	for (int i=9;i>=0;i--){
		for (int j=0;j<s.size();j++){
			if (a[j]!=-1 && i==a[j]-48){
				cout<<i;
				a[j]=-1;
			}
		}
	}
	
	
	
	return 0;
}
