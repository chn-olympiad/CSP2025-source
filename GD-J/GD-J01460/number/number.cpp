#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],num=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[num]=s[i]-'0';
			num++;
		}
	}sort(a,a+num+1);
	for(long long i=num;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
