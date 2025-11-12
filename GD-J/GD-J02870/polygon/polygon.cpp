#include <bits/stdc++.h>
using namespace std;
const long long M=998244353;
int n,mixb=0;
int a[5010],q[5010];
long long ans=0;
long long tmp[5010];
long long xh(int k,vector<int> tmp,int xb,int nowh){
	if(k==0){
		if(nowh>a[tmp[tmp.size()-1]]*2) return 1;
		return 0;
	}
	long long res=0;
	for(int i=xb+1;i<=n;i++){
		tmp.push_back(i);
		res+=xh(k-1,tmp,i,nowh+a[i])%M;
		tmp.erase(tmp.end());
	}
	return res%M;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) q[i]=a[i]+q[i-1];
	for(int i=3;i<=n;i++){
		vector<int> tmp;
		ans%=M;
		ans+=(xh(i,tmp,0,0)%M);
	}
	cout<<ans%M;
	return 0;
}
