#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<100;i++){
		a[i]=0;
	}
	for(int i=0;i<s.size();i++){
		if((s[i]-'0')>=0&&(s[i]-'0')<=9){
			a[s[i]-'0']++;
		}
	}     
	for(int i=10;i>=0;i--){
		if(a[i]!=0){
			while(a[i]--){
				cout<<i;
			}
		}
	}
	return 0;
}
