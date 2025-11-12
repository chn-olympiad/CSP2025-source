#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0;
struct A{
	int a1,a2,a3;
	bool f=0;
};
A a[100005];
struct Club{
	int ii,num;
};
Club c[4];
bool cmp(Club x, Club y){
	return x.num > y.num;
}
bool cmp1(A x, A y){
	return x.a1 > y.a1;
}
bool cmp2(A x, A y){
	return x.a2 > y.a2;
}
bool cmp3(A x, A y){
	return x.a3 > y.a3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	c[1].ii = 1;
	c[2].ii = 2;
	c[3].ii = 3;
	cin>>t;
	while(t--){
		c[1].num = 0;
		c[2].num = 0;
		c[3].num = 0;
		ans = 0;
		cin>>n;
		for(int i=1; i <= n; i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			c[1].num += a[i].a1;
			c[2].num += a[i].a2;
			c[3].num += a[i].a3;
		}
		sort(c+1,c+4,cmp);
		for(int i=1; i <= 3; i++){
			int cc = c[i].ii;
			if(cc==1) sort(a+1,a+n+1,cmp1);
			if(cc==2) sort(a+1,a+n+1,cmp2);
			if(cc==3) sort(a+1,a+n+1,cmp3);
			int k=n>>1;
			for(int j=1; j <= n; j++){
				if(k == 0) break;
				if(a[j].f) continue;
				if(cc==1) ans+=a[j].a1;
				if(cc==2) ans+=a[j].a2;
				if(cc==3) ans+=a[j].a3;
				a[j].f = 1;
				k--;
				//cout<<ans<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
