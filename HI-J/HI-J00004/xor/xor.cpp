#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long a[N];
long long n,k; 
int vis[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i] == k){
			sum++;
			vis[i]++;
		}
	}
	int first = n;
	int l=1,r=first-n+1;
//	cout<<l<<" "<<r<<" ";
	while(l!=1 || r!=first){
		n--;
		l=1,r=first-n+1;
		while(r<=first){
			bool ok = true;
			int tim=a[l];
			if(vis[l]) ok=false;
			for(int i=l+1;i<=r;i++){
				tim ^= a[i];
				if(vis[i]) ok=false;
			}
			if(tim == k){
				if(ok == true){
					sum++;
					for(int i=l;i<=r;i++){
						vis[i]++;
					}
//					cout<<l<<" "<<r<<"\n";
				}
			}
			l++;
			r++;
		}
		r--;
	}
//	for(int i=1;i<=first;i++){
//		cout<<vis[i]<<" ";
//	}
//	cout<<"\n";
//	for(int i=1;i<=first;i++){
//		if(vis[a[i]]>1){
//			sum = sum-vis[a[i]]+1;
//		}
//	}
	cout<<sum;
	
	return 0;
}
