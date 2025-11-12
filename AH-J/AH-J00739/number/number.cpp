#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int a,i,j;cin>>s;
    a=s.size();
    for(j='9';j>='0';j--){
    	for(i=0;i<a;i++){
    	    if(s[i]==j) cout<<j-'0';
    	}
    }
}
