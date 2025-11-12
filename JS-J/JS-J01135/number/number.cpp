#include<bits/stdc++.h>
using namespace std;
string x;
long long a[1000009],l;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	for(long long i=0;i<(long long)x.size();i++){
		if('0'<=x[i] && x[i]<='9'){
			l++;
			a[l]=(long long)(x[i]-'0');
		}
	}
	sort(&a[1],&a[l+1]);
	for(long long i=l;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
