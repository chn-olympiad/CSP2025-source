#include<bits/stdc++.h>
using namespace std;
const long maxn=1e6+5;
int t,op;
struct str{
	int a,b,c,r,s,t1;
}a[maxn];
bool cmp(str a,str b){
//	if(a.s==1){
//		if(b.s==1){
//			if(min(a.a-a.b,a.a-a.c)<b)
//		}
//	}if(b.s!=1){
//		
//	}
	if(a.s==op){
		if(b.s==op){
			return a.t1<b.t1;
		}else{
			return 1;
		}
	}else{
		if(b.s==op){
			return 0;
		}else{
			return a.t1<b.t1;
		}
	}
}
//bool cmpb(str a,str b){
//	return a.b>b.b;
//}
//bool cmpc(str a,str b){
//	return a.c>b.c;
//}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,aa=0,bb=0,cc=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>a[i].b){
				if(a[i].c>a[i].a){
					a[i].r=a[i].c,
					a[i].s=3,
					cc++;
					a[i].t1=min(a[i].c-a[i].a,a[i].c-a[i].b);
				}else{
					a[i].r=a[i].a,
					a[i].s=1,
					aa++;
					a[i].t1=min(a[i].a-a[i].c,a[i].a-a[i].b);
				}
			}else{
				if(a[i].c>a[i].b){
					a[i].r=a[i].c,
					a[i].s=3,
					cc++;
					a[i].t1=min(a[i].c-a[i].a,a[i].c-a[i].b);
				}else{
					a[i].r=a[i].b,
					a[i].s=2,
					bb++;
					a[i].t1=min(a[i].b-a[i].a,a[i].b-a[i].c);
				}
			}
		}
		if(aa>n/2){
			op=1;
			sort(a+1,a+n+1,cmp);
//			for(int i=1;i<=n;i++){
//				cout<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<endl;
//			}
			for(int i=1;i<=aa-n/2;i++){
				a[i].r=max(a[i].b,a[i].c);
			}
		}else if(bb>n/2){
			op=2;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=bb-n/2;i++){
				a[i].r=max(a[i].a,a[i].c);
			}
		}else if(cc>n/2){
			op=3;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=cc-n/2;i++){
				a[i].r=max(a[i].a,a[i].b);
			}
		}
		for(int i=1;i<=n;i++){
			ans+=a[i].r;
		}
		cout<<ans<<endl;
	}
	return 0;
}
