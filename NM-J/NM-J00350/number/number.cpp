#include<bits/stdc++.h>
using namespace std;
const int N=1e7+100;
string s;
int a=0,b[N],t=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    a=s.size();
    for(int i=0;i<a;i++){
        if(s[i]>='0' && s[i]<='9'){
            t++;
            b[t]=s[i]-'0';
        }
    }
    for(int i=1;i<=t;i++){
    	for(int j=1;j<=t-1;j++){
    		if(b[j]<b[j+1]){
    			swap(b[j],b[j+1]);
			}
		}
	}
    for(int i=1;i<=t;i++){
    	cout<<b[i];
    }
    return 0;
}