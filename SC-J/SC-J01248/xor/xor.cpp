#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
ll lenq(ll x){
	ll i=1,cnt=1,sum=1;
	while(1){
		if(x>sum){
			i++;
			cnt*=2;
			sum+=cnt;
		}
		else break;
	}
	return i;
}
struct aa{
	ll s,lenlen;
};
const int N=1e7;
ll n,ans=0;
aa a[N],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k.s;
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		a[i].lenlen=lenq(a[i].s);
	}
	k.lenlen=lenq(k.s);
	if(k.s==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i].s==0) cnt++;
		}
		cout<<cnt<<endl;
		return 0;
	}
	if(k.s==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i].s==1) cnt++;
		}
		cout<<cnt<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i].lenlen==k.lenlen){
			for(int j=i+1;j<=n;j++){
				if(a[i].s | a[j].s == k.s){
					
				}
				else{
					break;
				}
			}
		}
	}
	return 0;
} 