#include<bits/stdc++.h>
using namespace std;
long long a[200000000];
string k;
long long n;
bool c(long long a,long long b){
	return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>k;
    for(int i=0;i<k.size();i+=1){
    	if(k[i]>='0'&&k[i]<='9'){
    		a[n]=k[i]-'0';
    		n+=1;
		}
	}
	sort(a,a+n,c);
	for(int i=0;i<n;i+=1){
		cout<<a[i];
	}
	return 0;
}

