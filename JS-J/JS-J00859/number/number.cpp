#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000100],p;
bool cmp(int a,int b){
    return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto c:s)
        if(int('0')<=int(c) and int(c)<=int('9'))
               n[p++]=int(c)-int('0');
	sort(n,n+p,cmp);
	for(int i=0;i<p;i++){
        cout<<n[i];
	}
	return 0;
}
