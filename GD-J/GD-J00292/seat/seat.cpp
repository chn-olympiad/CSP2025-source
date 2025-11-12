#include<bits/stdc++.h>

using namespace std;

#define LL long long

const int N=1e4+7;

LL n,m,cnt,ans,a,b;
LL A[N];

bool cmp(LL x,LL y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>A[i];
	}
	ans=A[1];
	sort(A+1,A+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(A[i]==ans){
			cnt=i;break;
		}
	}
	a=(cnt-1)/n+1;
	cnt=(cnt-1)%n+1;
	if(a&1){
		b=cnt;
	}
	else{
		b=n-cnt+1;
	}
	cout<<a<<' '<<b<<endl;
	
	
	return 0;
}
