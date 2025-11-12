#include<bits/stdc++.h>
using namespace std;
string s;
long long a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-48]++;
		}
	}
	for(long long i=19;i>=0;i--){
		if(a[i]) for(int j=1;j<=a[i];j++) cout<<i;
	} 
	return 0;
}
