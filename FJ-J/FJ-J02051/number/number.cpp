#include<bits/stdc++.h>
using namespace std;
int s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n=a.size();
	for(int i=1;i<=n;i++){
		if(a[i-1]<='9'&&a[i-1]>='0'){
		    s[i]=a[i-1]-48;
		}
	    else{
	    	s[i]=10;
		}
	}
	sort(s+1,s+n+1);
	for(int i=n;i>=1;i--){
		if(s[i]<10){
			cout<<s[i];
		}
	}
    return 0;
}
