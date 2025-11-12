#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,ans=0; 
int a[N];
/*int xr(int a,int b){
	bool at[110],bt[110],rs[110];
	int act=0,bct=0,anss=0;
	int ak=a,bk=b;
	int btc[110]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
	while(ak!=0){
		at[act]=ak%2;
		ak=ak/2;
		++act;
	}
	while(bk!=0){
		bt[bct]=bk%2;
		bk=bk/2;
		++bct;
	}
	int p=max(act,bct);
	for(int i=0;i<=p;++i){
		if(at[i]!=bt[i])rs[i]=1;
		else rs[i]=0;
	}
	for(int i=0;i<=p;++i){
		if(rs[i])anss+=btc[i];
	}
	return anss;
}*/

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
	cin>>a[i];
	if(a[i]==k)++ans;
	}
	//真的写不出来了！！！
	cout<<ans;
	 
	return 0;
}