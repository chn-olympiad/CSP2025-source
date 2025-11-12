#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],pre[N];
bool mp[1<<20];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],pre[i]=pre[i-1]^a[i];
	int lst=0,res=0;mp[0]=1;
	for(int i=1;i<=n;i++){
		if(mp[(pre[i]^k)]){
			res++;
			for(int j=lst;j<i;j++)mp[pre[j]]=0;
			lst=i;
		}mp[pre[i]]=1;
	}cout<<res; 
	return 0;
} 
