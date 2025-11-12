#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
const int N=;
int a[N],b[N],c[N];
bool cmp(int g,int gg){
	if(a[g]!=a[gg])return a[g]>a[gg];
	if(b[g]!=b[gg])return b[g]>b[gg];
	return c[g]>c[gg];
}
int main(){
	freopen("club1.in","r",stdin);//ÑùÀý 
	//freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	sort(a+1,a+n+1,cmp);
	return 0; 
}
