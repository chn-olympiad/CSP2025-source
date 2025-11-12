#include <bits/stdc++.h>
using namespace std;
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long a[100000],n=0;
    long long si=s.length();
    for(long long i=0;i<si;i++){
    	if(s[i]=='0') a[i]=0,n++;
    	if(s[i]=='1') a[i]=1,n++;
    	if(s[i]=='2') a[i]=2,n++;
    	if(s[i]=='3') a[i]=3,n++;
    	if(s[i]=='4') a[i]=4,n++;
    	if(s[i]=='5') a[i]=5,n++;
    	if(s[i]=='6') a[i]=6,n++;
    	if(s[i]=='7') a[i]=7,n++;
    	if(s[i]=='8') a[i]=8,n++;
    	if(s[i]=='9') a[i]=9,n++;
    	else continue;
	}
	long long siz=sizeof(a);
	sort(a,a+n,cmp);
	for(long long i=0;i<n;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
