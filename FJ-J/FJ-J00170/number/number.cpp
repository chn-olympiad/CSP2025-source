#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000000],cnt=0,pd=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			if(s[i]=='0'){
				pd++;
			}
			cnt++;
		}
	}
	if(pd==cnt){
		cout<<"0";
	}else{
	sort(a,a+cnt);
	for(long long i=cnt-1;i>=0;i--){
		cout<<a[i];
	}
    }
	return 0;
}
