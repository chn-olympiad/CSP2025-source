#include <bits/stdc++.h>
using namespace std;
long long a[110000]={0};	
string s;
long long i;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			s[i]-='0';
			a[s[i]]++;
		}
	}	
	long long cnt=0;
	for(i=9;i>=0;i--){
		if(cnt==9&&i==0){
			cout<<0;
			return 0;
		}
		if(a[i]!=0){
			for(long long j=1;j<=a[i];j++){
				cout<<i;
			}
		}else{
			cnt++;
		}
	}
	return 0;
}
