#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
const int N=22;
int n;
int A[N];
long long ans;
bool check(int s){
	int sum=0,mx=0;
	int cnt=1;
	while(s!=0){
		if(s&1){
			sum=sum+A[cnt];
			mx=max(mx,A[cnt]);
		}
		s=s>>1;
		cnt++;
	}
	if(sum>2*mx) return 1;
	return 0;
}		
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	int S=1<<n;
	for(int s=3;s<=S;s++){
		if(check(s)) ans++;
		ans=ans%P;
	}
	cout<<ans;
	return 0;
}
