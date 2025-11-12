#include<bits/stdc++.h>
using namespace std;
int sz[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
    	if('0'<=a[i]<='9'){
    		sz[a[i]-'0']++;
		}
	}
	bool b=true;
	for(int i=9;i>=1;i--){
		while(sz[i]--) cout<<i;b=false;
	}
	if(b) cout<<0;
	else while(sz[0]--) cout<<0;
    return 0;
}