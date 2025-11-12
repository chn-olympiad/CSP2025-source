#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
struct A{
	int a1=0,a2=0,a3=0,vis=0;
}a[maxn];
bool cmp1(A x,A y){
	return x.a1 > y.a1;
}
bool cmp2(A x,A y){
	return x.a2 > y.a2;
	
}
bool cmp3(A x,A y){
	return x.a3 > y.a3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		memset(a,0,sizeof(a));
		int n,ans=0;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		sort(a+1,a+n+1,cmp1);
		for(int i=1,cnt=1;i<=n,cnt<=n/2;i++,cnt++)
			if(a[i].a1 >= a[i].a2 && a[i].a1 >= a[i].a3 && !a[i].vis) ans+=a[i].a1,a[i].vis=1;
		sort(a+1,a+n+1,cmp2);
		for(int i=1,cnt=1;i<=n,cnt<=n/2;i++,cnt++)
			if(a[i].a2 >= a[i].a1 && a[i].a2 >= a[i].a3 && !a[i].vis) ans+=a[i].a2,a[i].vis=1;
		sort(a+1,a+n+1,cmp3);
		for(int i=1,cnt=1;i<=n,cnt<=n/2;i++,cnt++)
			if(a[i].a3 >= a[i].a2 && a[i].a3 >= a[i].a1 && !a[i].vis) ans+=a[i].a3,a[i].vis=1;
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
