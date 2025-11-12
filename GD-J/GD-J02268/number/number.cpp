#include<bits/stdc++.h>
using namespace std;
string s;
long long num[1000005],n;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[n]=s[i]-48;
			n++;
		}
	}
	sort(num,num+n);
	for(int i=n-1;i>=0;i--){
		cout<<num[i];
	}
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	return 0;
}
