#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",in);
	freopen("number.out","w",out);
	string s;
	int a[10],n=0,sum=0;
	cin>>s;
    for(int i=1;i<=s.length();i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		n++;
    		a[n]+=s[i];
	    	}
    	}
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
    	sum+=a[i]*10^(n-1);
    	if(a[i]==0){
    		sum*=10;
		}
	}
	cout<<sum;
	return 0;
	}
