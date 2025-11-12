#include<bits/stdc++.h>
using namespace std;
int a[500000];
long long jc(int n){
	if(n==0||n==1) return 1;
	if(n<0) return -1;
	return jc(n-1)*n;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    bool cmp=1;
    for(int i=0;i<n;i++)
    {
		if(a[i]!=1) cmp=0;
	}
	if(cmp){
		switch(n){
		    case 1:cout<<0;return 0;
		    default:cout<<(jc(n)/(jc(n-2)*2));
		}
	}
    return 0;
}
