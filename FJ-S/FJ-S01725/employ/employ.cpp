#include<iostream>
#include<cstdio>
using namespace std;
int n,m,C[1010100],B[1010010],ans;
string a;
void quan(int nw,int be){
	//cout<<nw<<' '<<be<<'\n';
	if(nw>n){
		if(n-be>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(B[i]) continue;
		B[i]=1;
		if(a[nw-1]=='0') quan(nw+1,be+1);
		else if(be>=C[i]) quan(nw+1,be+1);
		else quan(nw+1,be);  
		B[i]=0;
	}
}
long long qiuq(int x){
	long long sum=1;
	for(int i=1;i<=x;i++) sum=(sum*i)%998244353;
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++) cin>>C[i];
	if(n>=10){
		int sum=0;
		for(int i=1;i<=n;i++) sum+=(C[i]==0);
		if(sum>n-m) cout<<0;
		else{
			if(sum==n-m) cout<<1;
			else{
			}
		}
		return 0;
	}
	quan(1,0);
	cout<<ans;
	return 0;
}
