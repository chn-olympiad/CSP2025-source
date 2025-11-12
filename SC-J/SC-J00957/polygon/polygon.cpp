#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
bool b[5005];
void solve(bool *b){
	long long maxn=-1,sumn=0,cnt=0;
	bool b0=0;
	for(int i=1;i<=n;i++){
		if(*(b+i)==0){
			sumn+=a[i];
			cnt++;
			maxn=max(maxn,a[i]);
			if(b0==0){
				*(b+i)=1;
				solve(b);
				*(b+i)=0;
			}
		}
		else b0=1;
	}
	if(sumn>maxn*2 && cnt>=3){
		ans++;
		ans%=998244353;
	} 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	solve(b);
	cout<<ans<<"\n";
}