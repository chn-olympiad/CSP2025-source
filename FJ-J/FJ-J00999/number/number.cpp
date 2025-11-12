#include<bits/stdc++.h>
using namespace std;
string s;
long long num[1000005],c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0' or s[i]=='1' or s[i]=='2'  or s[i]=='3' or s[i]=='4'  or s[i]=='5' or s[i]=='6'  or s[i]=='7' or s[i]=='8'  or s[i]=='9'){
			num[c]=int(s[i]-48);
			c++;
		}
	}
	sort(num,num+c+1);
	for(int i=c;i>0;i--){
		cout<<num[i];
	}
	
	
	return 0;
}
