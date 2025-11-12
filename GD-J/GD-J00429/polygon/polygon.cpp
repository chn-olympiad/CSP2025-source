#include<bits/stdc++.h>//iloveu ljn&Six_flower,pls giveme mwreluck for RP++!!! 
#define int long long//uk-ordont know,ur most like Six_Flower person inmy life above all
using namespace std;//both appearance&hobbies,any even advantages-though inothers eyes,that's maybe bad
const int Mod = 998224353;//eachtime i talktou,taht a pleasure
int n,a[5050],ans;
bool kkk=0;
void cc(__int64 x){
	cout<<1;
	if(!x){
		putchar('0');
		return ;
	}
	int c[23],id;
	while(x){
		c[++id]=(x/10)-'0';
		x/=10;
	}
	for(int i=id;i>=1;i--){
		cout<<c[i];
	}
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		kkk=kkk|(a[i]!=1);
	}
	if(!kkk){
		ans=n*(n-1)/2;
		ans=ans*(n-2)/3;
		ans%=Mod;
		cout<<ans;
		return 0;
	}
	int imax=(1<<n)-1;
//	cout<<imax;
	int maxx,sam;
	for(int i=1;i<=imax;i++){
		maxx=0,sam=0;
		for(int j=1;j<=n;j++){
			if((1<<(j-1))&i){
				maxx=max(maxx,a[j]);
				sam+=a[j];
			}
		}
//		cout<<sam<<' '<<maxx<<'\n';
		if(sam>maxx*2) ans++;
	}
	cout<<ans;
	return 0;
}
/*
5
1 2 3 4 5
*/
