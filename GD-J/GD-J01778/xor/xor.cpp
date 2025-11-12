#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000001];
bool vis=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			vis=true;
		}
	}
	if(m==0&&vis==0){
		cout<<n/2;
		return 0;
	}
	if(m==1||m==0){
		int ans=0;
		int da=0;
		for(int i=1;i<=n;i++){
			if(a[i]==m){
				ans++;
				da=0;
			}else if(da==0){
				da=a[i];
			}else{
				da=da^a[i];
				if(da==m){
					da=0;
					ans++;
				}
			}
		}
		cout<<ans;
	}
}
