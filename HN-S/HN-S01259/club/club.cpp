#include<bits/stdc++.h>
using namespace std;
int n,t,max_=-1,vis[100010];
struct a1{
	int k1,k2,k3;
}a[1000010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int qq=1;qq<=t;qq++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].k1>>a[i].k2>>a[i].k3;
		}
		long long sum=0;
		int asd;
		for(int i=1;i<=n/2;i++){
			max_=-1;
			for(int j=1;j<=n;j++){
					if(a[j].k1>max_&&vis[j]==0){
						max_=a[j].k1;
						asd=j;
						continue;
					}
			}
			sum+=max_;
			vis[asd]=1;
		}
		cout<<sum<<endl;
	}
	return 0;
}
