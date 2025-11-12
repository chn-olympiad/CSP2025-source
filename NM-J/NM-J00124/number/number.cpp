#include<bits/stdc++.h>
using namespace std;
string s;
int b[1000060];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.length(),cnt=0;
    for(int i=0;i<l;i++){
    	if(isdigit(s[i])==1){
    		b[cnt]=int(s[i]-'0');
    		cnt++;
		}
	}
	sort(b,b+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<b[i];
	}
    return 0;
}
