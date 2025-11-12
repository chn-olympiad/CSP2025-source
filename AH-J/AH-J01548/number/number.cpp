#include<bits/stdc++.h>
using namespace std;
string s;
long long i,n,t[110],d,z,j;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    z=s.size();
    n=0;
    for(i=0;i<z;i++){
	    if(s[i]>='0'&&s[i]<='9'){
			n++;
			t[s[i]-'0']++;
		}	
	}
	for(i=9;i>=0;i--){
		for(j=1;j<=t[i];j++){
		    cout<<i;	
		}	
	}
    return 0;
}
