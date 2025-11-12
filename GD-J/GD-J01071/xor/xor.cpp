#include<bits/stdc++.h>
using namespace std;
long long n,k;//1048576
long long a[500100];
long long t=0;
long long s[500100],kkl=1;
struct str{
	long long st,ed;
}sum[500100];
bool cmp(str x,str y){
	if(x.ed==y.ed) return x.st<y.st;
	return x.ed<y.ed;
}
void solve1(){
	for(long i=1;i<=n;i++){
		if(a[i]!=a[1]) return ;
	}
	if(k==a[1]){
		cout<<n;
		t=1;
		return ;
	}
	else if(k==0){
		cout<<n/2;
		t=1;
		return ;
	}
	else{
		cout<<0;
		t=1;
		return ;
	}
}
void solve2(){
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(j==i){
				if(a[i]==k){
					sum[kkl].st=i;
					sum[kkl].ed=j;
					kkl++;
				}
			}
			if((s[j]^s[i-1])==k&&i!=j){
				sum[kkl].st=i;
				sum[kkl].ed=j;
				kkl++;
			}
		}
	}
	long long ans=1;
	sort(sum+1,sum+kkl,cmp);
	for(long long i=1;i<kkl;i++){
		for(long long j=i+1;j<kkl;j++){
			if(sum[i].ed<sum[j].st){
				ans++;
				i=j-1;
				break;
			}
		}
	}
	cout<<ans;
	t=1;
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	solve1();
	if(t==1) return 0;
	solve2();
	if(t==1) return 0;
	
	return 0;
}
