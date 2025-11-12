#include<bits/stdc++.h>
using namespace std;
long long s,a[1000005],i=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(;s>0;i++,s=s/10){
		a[i]=s%10;
	}
	sort(a,a+i);
	for(i=i-1;i>=1;i--) cout<<a[i];
	return 0;
}  
