#include<bits/stdc++.h>
using namespace std;
long long a[1000005],zzz_=0;
string x;
bool cmp(long long k,long long l){
	return k>l;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	long long y=x.size();
	for(long long i=0;i<y;i++){
		if('0'<=x[i]&&'9'>=x[i]){
			a[zzz_]=x[i]-'0';
			zzz_++;
		}
	}
	sort(a,a+zzz_,cmp);
	for(long long i=0;i<zzz_;i++){
		cout<<a[i];
	}
	return 0;
}