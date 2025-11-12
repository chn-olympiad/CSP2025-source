#include<bits/stdc++.h>
using namespace std;
string s,c;
long long a[2000010],x;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long n=s.size();
    for(int i=0;i<n;i++){
	    if(s[i]>='0' && s[i]<='9'){
	    	c[x]=s[i];
	    	x++;
		}
    }
    for(int i=0;i<x;i++){
    	a[i]=(long long)c[i]-48;
	}
	sort(a,a+x);
	for(int i=x-1;i>=0;i--){
    	cout<<a[i];
	}
    return 0;
}