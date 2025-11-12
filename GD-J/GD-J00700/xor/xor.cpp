#include<iostream>
#include<unordered_map>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],sum[N];
unordered_map<int,int> lst;
int cur=0;
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]==k) ans++,cur=i;
		else if(sum[i]==k&&cur==0) ans++,cur=i;
		else if(lst[sum[i]^k]!=0&&lst[sum[i]^k]+1>cur) ans++,cur=i;
		lst[sum[i]]=i;
	}
	cout<<ans;
	return 0;
}
