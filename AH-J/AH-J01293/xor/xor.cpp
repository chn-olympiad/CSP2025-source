#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool vis[500005];
int f(int l,int r){
	return a[r]^a[l-1];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x^a[i-1];
	}
	for(int l=1;l<=n;l++){
		for(int r=1;r<=n;r++){
			if(r<l){
				continue;
			}
			if(f(l,r)==k){
				bool f=1;
				for(int i=l;i<=r;i++){
					if(vis[i]){
						f=0;
						break;
					}
				}
				if(!f){
					break;
				}
				for(int i=l;i<=r;i++){
					vis[i]=1;
				}
				cnt++;
//				cout<<l<<" "<<r<<endl;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
