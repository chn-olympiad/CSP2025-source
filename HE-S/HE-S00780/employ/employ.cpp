#include<bits/stdc++.h>
using namespace std;
int T,n;
struct jie{
	int yisancha,yiercha;
	int xiaocha;
}a[114514];
bool cmp(jie x,jie y){
	return x.xiaocha<y.xiaocha;
}
bool cmp12(jie x,jie y){
	return x.yiercha<y.yiercha;
}
bool cmp13(jie x,jie y){
	return x.yisancha<y.yisancha;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>T;
	while(T--){
		int qwe=1,erg=0,sang=0,p1=0,p2=0;
		long long he=0;
		cin>>n;
		for(int i=1,x,y,z;i<=n;i++){
			cin>>x>>y>>z;
			he+=x;
			a[i].yiercha=x-y;
			a[i].yisancha=x-z;
			if(a[i].yiercha>a[i].yisancha){
				a[i].xiaocha=a[i].yisancha;
			}
			else{
				a[i].xiaocha=a[i].yiercha;
			}
			
		}
		sort(a+1,a+1+n,cmp);
		int xiao=a[qwe].xiaocha;
		while(xiao<=0){
			int aq=a[qwe].xiaocha;
			int ae=a[qwe].yiercha;
			int as=a[qwe].yisancha;
			qwe++;
			if(erg==n/2&&aq==ae){
				continue;
			}
			else if(sang==n/2&&aq==as){
				continue;
			}
			else{
				if(aq==as){
					sang++;
				}
				else{
					erg++;
				}
				he-=aq;
			}
			if(sang==n/2&&p1==0){
				p1=1;
				sort(a+qwe,a+1+n,cmp12);
				continue;
			}
			if(erg==n/2&&p2==0){
				p2=1;
				sort(a+qwe,a+1+n,cmp13);
				continue;
			}
			if(p1){
				xiao=a[qwe].yiercha;
			}
			else if(p2){
				xiao=a[qwe].yisancha;
			}
			else{
				xiao=a[qwe].xiaocha;
			}
		}
		for(int i=qwe;i<=n/2;i++){
			if(p1){
				he-=a[i].yiercha;
			}
			else if(p2){
				he-=a[i].yisancha;
			}
			else{
				he-=a[i].xiaocha;
			}
		}
		cout<<he;
		for(int i=1;i<=n;i++){
			a[i].xiaocha=0;
			a[i].yiercha=0;
			a[i].yiercha=0;
		}
	}
	
	return 0;
}
