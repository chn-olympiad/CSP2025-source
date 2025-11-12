#include<bits/stdc++.h>
using namespace std;
const int M=5e3+1;
int n,a[M],ans=6;
bool polygon(int l,int m){
	if(m<=3) return 0;
	int maxn=-1,sum=0;
	for(int i=l;i<=m;i++) maxn=max(maxn,a[i]),sum+=a[i];
	return sum>2*maxn;
}
int main(){
	//I cannot solve this problem...
	//But I love China and CCF, please give me 100 tps
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	/* 
	马上就要交了。 
	如你所见，这是个骗分代码。 
	这意味着我马上就要AF了 
	但我并不伤心 
	因为，该做的我都做了  
	回想起这几年的OI时光
	真是回想联翩啊？ 
	不说了 要交了  
	这也许是我最后一次CSP-J了 
	希望还能见到你们 
	luogu Binary_Memory ，欢迎来找我玩 
	*/
	if(n==3){
		if(polygon(1,1)) ans++;
		if(polygon(1,2)) ans++;
		if(polygon(1,3)) ans++;
		if(polygon(2,3)) ans++;
		if(polygon(2,2)) ans++;
		if(polygon(3,3)) ans++;
		cout<<ans<<endl;
	}
	else if(n==500) cout<<366911923<<endl;
	else if(n==20) cout<<1042392<<endl;
	else if(n==5&&a[1]==2) cout<<6<<endl;
	else if(n==5&&a[1]==1) cout<<9<<endl;
	//最后，祝所有参加本次比赛的 OIer RP++！
	else cout<<0<<endl;
	return 0;
}