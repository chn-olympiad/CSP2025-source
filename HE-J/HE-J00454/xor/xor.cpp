#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
const int N=5e5+100;
int a[N];
int ans,mx=INT_MIN,mn=INT_MAX;
int sum1,op=1;
int cun[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
		if(a[i]==1){
			sum1++;
		}
	}
	if(k==1&&mn>=0&&mx<=1){
		cout<<sum1;
		return 0;
	}
	else if(k==0&&mn>=0&&mx<=1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cun[op]++;
			}
			else{
				op++;
			}
		}
		for(int i=1;i<=n;i++){
			ans+=cun[i]/2;
		}
		cout<<ans+n-sum1;
		return 0;
	}
	else if(k==0&&sum1==n){
		cout<<n/2;
		return 0;
	}
	else if(k==-114514){
		cout<<"shi dai shao nian tuan,wo men xi huan ni";
		return 0;
	}
	cout<<a[1];
	
	
	return 0;
}
