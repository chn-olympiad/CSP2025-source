#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n;
int t;
int d;

struct aaa{
	long long a,b,c,p;
}T[N];
bool cmp(aaa x,aaa y){
	return x.p>=y.p;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j = 1;j<=t;j++){
		cin>>n;
		int a1=0,b1=0,c1=0;
		int ans=0;
		for(int i = 1;i<=n;i++){
			cin>>T[i].a>>T[i].b>>T[i].c;
			T[i].p=max(T[i].a,max(T[i].b,T[i].c));
		}
		sort(T+1,T+n+1,cmp);
		d = n/2;
		for(int i = 1;i<=n;++i){
			int tmp;
			if(T[i].a>=T[i].b&&T[i].b>=T[i].c) tmp = 1;
			if(T[i].a>=T[i].c&&T[i].c>=T[i].b) tmp = 1;
			
			if(T[i].b>=T[i].a&&T[i].a>=T[i].c) tmp = 2;
			if(T[i].b>=T[i].c&&T[i].c>=T[i].a) tmp = 2;
			
			if(T[i].c>=T[i].b&&T[i].b>=T[i].a) tmp = 3;
			if(T[i].c>=T[i].a&&T[i].a>=T[i].b) tmp = 3;
			
			if(tmp==1){
				a1++;
				if(a1<=d) ans+=T[i].p;
				else{
					a1--;
					T[i].a==-1;
					T[i].p = max(T[i].b,T[i].c);
					sort(T+1,T+n+1,cmp);
					continue;
				}
			}
			else if(tmp==2){
				b1++;
				if(b1<=d) ans+=T[i].p;
				else{
					b1--;
					T[i].b==-1;
					T[i].p = max(T[i].a,T[i].c);
					sort(T+1,T+n+1,cmp);
					continue;
				}
			}
			else if(tmp==3){
				c1++;
				if(c1<=d) ans+=T[i].p;
				else{
					c1--;
					T[i].c==-1;
					T[i].p = max(T[i].a,T[i].b);
					sort(T+1,T+n+1,cmp);
					continue;
				}
			}
			
		}
		cout<<ans<<endl;
	}
}
