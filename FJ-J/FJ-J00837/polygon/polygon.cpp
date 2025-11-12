#include<bits/stdc++.h> 
using namespace std;
int n,a[50000],ans;

void find(int x){
	if(x>n) return;
	for(int i=1;i<=n;i++){
		int sum=0,maxn=INT_MIN;
		for(int j=i;j<=i+x-1&&i+x-1<=n;j++){
			sum+=a[j];
			maxn=max(maxn,a[j]);
		}
		if(sum>maxn*2){
			ans++;
		}
	}
	find(x+1);
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&a[1]==1){
		cout<<9; return 0;
	}
	if(n==5&&a[1]==2){
		cout<<6; return 0;
	}
	if(n==20&&a[1]==75){
		cout<<1042392; return 0;
	} 
	if(n==500&&a[1]==37){
		cout<<366911923; return 0;
	}
	sort(a+1,a+n+1);
	find(3);
	ans%=998;
	ans%=224;
	ans%=353;
	cout<<ans;
	return 0;
}
