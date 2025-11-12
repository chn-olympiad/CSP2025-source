#include<bits/stdc++.h>
using namespace std;
string s;
long long a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size()-1;
	for(int i=0;i<=len;i++){
		if(s[i]>=48&&s[i]<=57){
			a[int(s[i])-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	cout<<endl;
	return 0;
}