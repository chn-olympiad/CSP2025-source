#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],z=0,t=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[z++]=(s[i]-'0');
			if(s[i]-'0'!=0)t=1;
		}
	}
	sort(a+0,a+z);
	if(t==0){
		cout<<0;
		return 0;
	}
	for(int i=z-1;i>=0;i--){
		cout<<a[i];
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
