#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
using namespace std;
int t;
int n;
struct cc{
	int a,b,c,id;
}m[100005];
bool cmp1(cc q,cc w){
	if(q.a==w.a){
		if(q.b==w.b) return q.c>w.c;
		return q.b>w.b;
	}
	return q.a>w.a;
}
bool cmp2(cc q,cc w){
	if(q.id==w.id){
		if(q.id==1) return q.a>w.a;
		if(q.id==2) return q.b>w.b;
		if(q.id==3) return q.c>w.c;
	}
	return q.id<w.id; 
}
int main()
{
	IOS
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>m[i].a>>m[i].b>>m[i].c,m[i].id=0;
		sort(m+1,m+n+1,cmp1);
		int x=0,y=0,z=0;
		ll ans=0;
		for(int i=1;i<=n;i++){
			int qq=m[i].a,ww=m[i].b,ee=m[i].c;
			if(qq>=ww&&qq>=ee) {
				if(x<n/2) ans+=qq,x++,m[i].id=1;
				else if(ww>=ee) ans+=ww,y++,m[i].id=2;
				else ans+=ee,z++,m[i].id=3; 
			}
			else if(ww>=qq&&ww>=ee) {
				if(y<n/2) ans+=ww,y++,m[i].id=2;
				else if(qq>=ee) ans+=qq,x++,m[i].id=1;
				else ans+=ee,z++,m[i].id=3; 
			}
			else if(ee>=ww&&ee>=qq) {
				if(z<n/2) ans+=ee,z++,m[i].id=3;
				else if(qq>=ww) ans+=qq,x++,m[i].id=1;
				else ans+=ww,y++,m[i].id=2; 
			}
		}
		sort(m+1,m+n+1,cmp2);
		int ma=0,t=0;
		for(int i=1;i<=x;i++){
			ma=0;t=0;
			int qq=m[i].a,ww=m[i].b,ee=m[i].c;
			for(int j=x+1;j<=x+y;j++){
				if(qq+m[j].b<ww+m[j].a){
					ma=max(ma,(ww+m[j].a)-(qq+m[j].b));
					if(ma==(ww+m[j].a)-(qq+m[j].b)) t=j;
					//break;
				}
			}
			if(t)
				swap(m[i],m[t]),swap(m[i].id,m[t].id);
			ans+=ma; t=0;
			ma=0;
			for(int k=x+y+1;k<=n;k++){
				if(qq+m[k].c<ee+m[k].a){
					ma=max(ma,(ee+m[k].a)-(qq+m[k].c));
					if(ma==(ee+m[k].a)-(qq+m[k].c)) t=k;
					//break;
				}
			}
			if(t) swap(m[i],m[t]),swap(m[i].id,m[t].id);
			ans+=ma;
		}
		for(int i=x+1;i<=x+y;i++){
			ma=0;t=0;
			int ww=m[i].b,ee=m[i].c;
			for(int j=x+y+1;j<=n;j++){
				if(ww+m[j].c<ee+m[j].b){
					ma=max(ma,(ee+m[j].b)-(ww+m[j].c));
					if(ma==(ee+m[j].b)-(ww+m[j].c)) t=j;
					//break;
				}
			}
			if(t){
				swap(m[i],m[t]);
					swap(m[i].id,m[t].id);
			}
			ans+=ma;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
