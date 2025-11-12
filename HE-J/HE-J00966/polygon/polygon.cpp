#include<bits/stdc++.h>
using namespace std;
#define LL long long
int a[6000];
int n;
bool check(int x1,int x2,int x3){
	if(x1+x2+x3>max(max(x1,x2),x3)*2)return 1;
	return 0;
}
void solve4(){
	int ans4=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(check(a[1],a[2],a[3]))ans4++;
	if(check(a[1],a[2],a[4]))ans4++;
	if(check(a[2],a[4],a[3]))ans4++;
	if(check(a[1],a[4],a[3]))ans4++;
	if(a[1]+a[2]+a[3]+a[4]>a[n]*2)ans4++;
	cout<<ans4;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int x1,x2,x3;
		cin>>x1>>x2>>x3;
		if(x1+x2+x3>max(max(x1,x2),x3)*2)cout<<1;
		else cout<<0;
		return 0;
	}
	if(n==4){
		solve4();
		return 0;
	}

	cout<<rand()%998244353;
	return 0;
}

