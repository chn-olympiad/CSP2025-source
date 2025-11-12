#include<bits/stdc++.h>
using namespace std;
bool ta=1,tb=1;
int n,k;
int ans=0;
int a[500005];
int sum[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) ans++;
		sum[i]=sum[i-1]^a[i];
		if(a[i]!=1) ta=0;
		if(a[i]!=0&&a[i]!=1) tb=0;
	}
	if(ta){
		if(k==0) cout<<n/2;
		else if(k==1) cout<<n;
		else cout<<0;
		return 0;
	}
	if(tb){
		int sum=0;
		for(int i=1;i<=n;i++) sum+=a[i];
		if(k==1) cout<<sum;
		else if(k==0) cout<<sum/2;
		else cout<<0;
		return 0;
	}
	int lst=0;
	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			if(a[i]==k){
//				s[++ans]=i;
//			}
//		}
		for(int j=i;j<=n;j++){
			if(a[j]==k||j==n){
//				if(a[j]==k) ans++,cout<<"&&&";
				if(j==n&&a[j]!=k) j++;
				bool fl=0;
//				cout<<lst<<"--------"<<j<<"\n";
				for(int o=lst+1;o<=j-1;o++){
					for(int p=lst+1;p<=o;p++){
						if((sum[o]^sum[p-1])==k){
//							cout<<p<<"->"<<o<<"   "<<sum[o]<<"^"<<sum[p-1]<<"\n";
							ans++;
//							cout<<"***";
							lst=o;i=o;
							fl=1;
							break;
						}
					}
					if(fl) break;
				}
				if(fl) break;
				lst=j;i=j;
			}
		}
	}
//	s[ans+1]=n+1;
	cout<<ans;
	return 0;
}
/*
10 2
2 1 0 3 2 1 0 3 3 2
*/
