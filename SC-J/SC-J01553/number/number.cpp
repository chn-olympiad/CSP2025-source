#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=s.size();
	for(int i=9;i>=0;i--){
		for(int j=0;j<k;j++){
			int q=(s[j]-'0');
			if(q==i)cout<<i;
		}
	}
	return 0;
}