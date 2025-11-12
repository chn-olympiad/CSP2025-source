#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
int t[25];
bool bidui(int x){
	int kk=k;
	while(kk){
		if(kk%2==1){
			if(x%2==0) return 0;
		}
		kk=kk>>1;
		x=x>>1;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool s1=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1&&a[i]!=0){
			s1=0;
			break;
		}
	}
	if(s1==1){
		int ans=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else{
					if(a[i-1]==1) ans++;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
		}
		cout<<ans;
		return 0;
	}
//	if(n<=1000){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				a[i]=-1;
				ans++;
				continue;
			}
			int x=0;
			for(int j=i;j>=1&&a[j]!=-1;j--){
				x^=a[j];
				
				if(x==k){
//					cout<<j<<" "<<i<<" "<<x<<"\n";
					ans++;
					a[i]=-1;
					break;
				}
			}
		}
		cout<<ans;
//		return 0;
//	}
	
	

	return 0;
}

//	int ans=0;
//	int l=1,r=1;
//	int x=a[1];
//	while(l<=r&&l<=n&&r<=n){
//		cout<<l<<" "<<r<<" "<<x<<" ";
//		if(x==k){
//			r+=1;
//			l=r;
//			ans++;
//			x=a[l];
//			continue;
//		}
//		if(l==r){
//			r++;
//			x^=a[r];
//			continue;
//		}
//		bool d=bidui(x);
//		cout<<d<<"\n";
//		if(d==1){
//			int f=bidui(x^a[l]);
////			cout<<f<<"\n";
//			if(f==1){
//				x^=a[l];
//				l++;
//				
//			}
//			else{
//				r++;
//				x^=a[r];
//			}
//		}
//		else{
//			r++;
//			x^=a[r];
//		}
//	}
//	cout<<ans;
//written by smartjohn