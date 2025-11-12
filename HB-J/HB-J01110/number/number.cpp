#include<bits/stdc++.h>
using namespace std;
string a;
long long s[1000002],x=1;;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long i=0;i<a.size();i++){
		if(a[i]-48<10&&a[i]-48>=0){
			s[x++]=a[i]-48;
		}
	}
	sort(s+1,s+x);
	for(long long i=x-1;i>0;i--){
		cout<<s[i];
	}
	return 0;
}
