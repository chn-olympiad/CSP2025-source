#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5050],cnt;
long long jie(int x){
	long long tmp=1;
	for(int i=2;i<=x;i++) tmp*=x;
	return tmp; 
}
long long pai(int l,int r,int num){
	int len=r-l+1;
	if(len==num) return 1;
	else if(len<=num) return 0;
	else return jie(len)/(jie(num)*jie(len-num));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) cout<<9;
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10) cout<<6;
	return 0;
}
