#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	s=s+'A';
	long long a[10]={0};
	for(long long i=0; ;i++){
		if(s[i]=='A'){
			break;
		}
        if(s[i]-'0'<='9'&&s[i]>='0'){
        	a[s[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--){
		for(long long j=0;j<a[i];j++){
		    cout<<i;
	    }
	}
	return 0;
} 
