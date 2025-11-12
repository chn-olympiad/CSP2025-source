#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==0){
		int num=0;
		for(int i=1;i<=n;i++)
			if(a[i]==0)num++;
		cout<<num<<endl;
		return 0;
	}
	if(m==1){
		int num=0;
		for(int i=1;i<=n;i++)
			if(a[i]==1)num++;
		cout<<num<<endl;
		return 0;
	}
	int num=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		num+=a[i];
		if(num>m)
			num-=2*a[i];
		if(num==m){
			num=0;
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
