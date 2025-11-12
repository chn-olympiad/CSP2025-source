#include<bits/stdc++.h>
using namespace std;
long long b[1000005];
int cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    long long l=a.size();
    long long j=0;
    for(long long i=0;i<l;i++){
    	if(a[i]<='9'&&a[i]>='0'){
    		b[j]=a[i]-'0';
    		j++;
		}
	}
    sort(b,b+j,cmp);
	for(int i=0;i<j;i++)cout<<b[i];
    return 0;
}
