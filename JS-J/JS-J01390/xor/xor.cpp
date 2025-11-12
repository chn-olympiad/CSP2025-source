#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N],k,cnt;
int n;
long long sum(int l,int r){
	long long tmp=a[l];
	for(int i=l+1;i<=r;i++){
		tmp^=a[i];
	}
	return tmp;
}
void find(long long k,int l,int r){
	if(l>=r) return;
	for(int i=l;i<=r;i++){
		long long ans1=sum(l,i);
		long long ans2=sum(i,r);
		if(ans1==k||ans2==k){
			cnt++;
			find(k,l,i-1);
			find(k,i+1,r);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	find(k,1,n);
	cout<<cnt;
	return 0;
}
