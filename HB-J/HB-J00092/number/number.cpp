#include<bits/stdc++.h>
using namespace std;
string r;
long long a[1000010],n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>r;
	for(int i=0;i<r.length();i++){
		if(r[i]>='0' && r[i]<='9'){
			a[n]=r[i]-'0';
			n++;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)cout<<a[i];
	return 0;
}
