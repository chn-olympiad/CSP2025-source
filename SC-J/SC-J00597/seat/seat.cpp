#include<bits/stdc++.h>
using namespace std;
#define ak ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//don't use fclose
//不开ll___
//数组开小直接炸
#define sqrt sqrtl
#define int long long
const int maxn=500;
int a[maxn];
inline int randr(int l,int r){return rand()%(r-l+1)+l;}
#define randf(l,r) for(int i=l;i<=r;i=randr(l,r))
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int st=n*m;
	for(int i=1;i<=st;i++)cin>>a[i];
	int sc=a[1];
	sort(a+1,a+st+1);
	reverse(a+1,a+st+1);
	int rk=1;
	while(1){
		if(a[rk]==sc)break;
		rk++;
	}
	//n行m列
	//[1,n][n+1,2n]
	int l=(rk-1)/m+1,rm=rk%n,h;
	if(rm==0)rm=n;
	//2 s 2=2
	//1 s 2=1
	//3 s 2=1
	//应该是rk
	if(l%2==0){//从下往上
		h=n-rm+1;
	}
	else h=rm;
	cout<<l<<' '<<h;
	return 0;
}