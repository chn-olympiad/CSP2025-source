#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
vector<int>a(N,0);
int n,k,ans=0;
bool check(int x){
	int cnt=0,j=0;
	bool flag=true;
	while(1){
		int num=0,jj=j;
		for(int i=j+1;i<=n;i++){
			if(!num)	num=a[i];
			else	num^=a[i];
			if(num==k){
				cnt++;
				j=i;
				break;
			}
		}
		if(j==n)	break;
		if(j==jj){
			flag=false;
			break;
		}
	}
	if(cnt<x)	flag=false;
	return flag&&x>=ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else	r=mid-1;
	}
	cout<<ans;
	return 0;
}