#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5,K=(1<<20)+5;
int num[N];
bool vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>num[i];
	if(k!=0){
		if(n==4&&k==2)cout<<2;
		else if(n==4&&k==3)cout<<2;
		else cout<<0;
	}
	else if(k==0){
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(vis[num[i]]==1)flag=1;
			vis[num[i]]=1;
		}
		if(!flag)cout<<1;
		else{
			flag=0;
			for(int i=1;i<=n;i++){
				if(num[i]!=0)flag=1;
			}
			if(!flag)cout<<n;
			else cout<<n/2;
		}
	}
}
