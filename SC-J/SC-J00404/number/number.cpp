#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int len,n,a[N];
char t[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t+1;
	for(int i=1;i<=N;i++){
		if(t[i]=='0') a[++n]=0;
		if(t[i]=='1') a[++n]=1;
		if(t[i]=='2') a[++n]=2;
		if(t[i]=='3') a[++n]=3;
		if(t[i]=='4') a[++n]=4;
		if(t[i]=='5') a[++n]=5;
		if(t[i]=='6') a[++n]=6;
		if(t[i]=='7') a[++n]=7;
		if(t[i]=='8') a[++n]=8;
		if(t[i]=='9') a[++n]=9;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
		cout<<a[i];
	return 0;
}