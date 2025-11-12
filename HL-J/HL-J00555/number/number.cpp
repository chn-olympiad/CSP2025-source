#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    short a[1000001]={};
    cin>>s;
    int len=s.length();
    s=" "+s;
    int cnt=0;
    for(int i=1;i<=len;i++){
    	if(s[i]>'9'||s[i]<'0'){
    		continue;
		}
		a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

