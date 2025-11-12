#include <bits/stdc++.h>
using namespace std;
string a;
int aa[1000000],s=1,ans,k=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if('0'<=a[i]&&a[i]<='9'){
			aa[s]=int(a[i])-48;
			s++;
		}
	}
	sort(aa+1,aa+1+s);
	
	for(int i=1;i<=s;i++){
		ans+=aa[i]*k;
		k*=10;
	}
	cout<<ans/10;
	return 0;
}
