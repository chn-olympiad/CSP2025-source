#include<iostream>
#include<iomanip>
#include<string>
#include<cstdio>
#include<queue>
#include<vector>
#include<stack>
#include<math.h>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e5+5;
ll T,n;
ll f[N][5];
struct stu{
	ll ad;
	ll s[5];
}a[N];
/*bool cmpa(stu x,stu y){
	return x.s[1]>y.s[1];
}
bool cmpb(stu x,stu y){
	return x.s[2]>y.s[2];
}
bool cmpc(stu x,stu y){
	return x.s[3]>y.s[3];
}*/
bool cmp(stu x,stu y){
	return max(x.s[1],max(x.s[2],x.s[3]))>max(y.s[1],max(y.s[2],y.s[3]));
}
ll solve(ll n){
	ll numa=0,numb=0,numc=0;
	for(int i=1;i<=n;i++){
		a[i].ad=i;
		cin>>a[i].s[1]>>a[i].s[2]>>a[i].s[3];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i].ad<<" "<<a[i].s[1]<<" "<<a[i].s[2]<<" "<<a[i].s[3]<<'\n';
	}
	ll maxn=max(f[n][1],max(f[n][2],f[n][3]));
	return maxn;
}
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	
	cin>>T;
	while(T--){
		cin>>n;
		cout<<solve(n)<<'\n';
	}
	
	
	//fclose(stdin);fclose(stdout);
	
	return 0;
}
