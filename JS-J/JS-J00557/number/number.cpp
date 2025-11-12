#include<bits/stdc++.h>
using namespace std;
int n[1000005];int ii=1,a=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if((s[i]-'0')>=0 && (s[i]-'0')<=9){
			n[ii]=s[i]-'0';
			ii++;
		}
	}
	sort(n+1,n+ii);
	for(int i=ii-1;i>=1;i--){
	    cout<<n[i];
	}

    return 0;
}
