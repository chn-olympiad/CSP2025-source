#include<bits/stdc++.h>
using namespace std;
#define int long long
char s[1000005];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=strlen(s);
    sort(s,s+n);
    for(int i=0;i<n;i++){
	    if(s[i]>'9'){
		    n=i;
		}
	}
	for(int i=n-1;i>=0;i--){
	    cout<<s[i];
	}
    return 0;
}
