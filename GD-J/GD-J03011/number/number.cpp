#include<bits/stdc++.h>
using namespace std;
string s;
long long a[15],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[int(s[i])-48]++;
			n++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			while(a[i]>0){
				cout<<i;
				a[i]--;
			}
		} 
	}
	return 0;
}
