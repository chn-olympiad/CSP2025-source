#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
long long a[N];
long long cnt;
int n;
void stu(int x,long long maxn,long long sum,int k){
	if(x==n+1){
		if(maxn*2<sum&&k>2){
			cnt=(cnt+1)%998244353;
		}
		return ;
		cout<<endl;
	}
	stu(x+1,max(maxn,a[x]),sum+a[x],k+1);
	stu(x+1,maxn,sum,k);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stu(1,-1e9,0,0);
	cout<<cnt%998244353;
	//#Shang4Shan3Ruo6Shui4
	return 0;
}
