#include<bits/stdc++.h>
using namespace std;
const int inf = 1e5+5;
int t,n,ans,ct,db[inf],dc[inf],dd[inf];
struct node {
	int a,b,c,id;
} md[inf];
bool cmp(node x,node y) {
	if(x.a==y.a) {
		if(x.b==y.b)return x.c<y.c;
		return x.b<y.b;
	}
	return x.a<y.a;
}
void f(int high,int sum,int na,int nb,int nc) {
	if(high==n+1) {
		if(ans<sum)ans=sum;
		return;
	}
	if(na<ct)f(high+1,sum+md[high].a,na+1,nb,nc);
	if(nb<ct)f(high+1,sum+md[high].b,na,nb+1,nc);
	if(nc<ct)f(high+1,sum+md[high].c,na,nb,nc+1);
}
bool dmp(node x,node y) {
	return dd[x.id]<dd[y.id];
}
bool cmp2(node x,node y) {
	return x.c>y.c;
}
bool bmp(node x,node y) {
	return x.b>y.b;
}
bool amp(node x,node y) {
	return x.a>y.a;
}
int g(int x,int y) {
	if(x==0&&y==0)return 1;
	return 0;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		if(n<=30) {
			ans=0;
			for(int i=1; i<=n; i++)cin>>md[i].a>>md[i].b>>md[i].c;
			sort(md+1,md+n+1,cmp);
			ct=n/2;
			f(1,0,0,0,0);
			cout<<ans<<endl;
		} else {
			int suma=0,sumb=0,sumc=0;
			for(int i=1; i<=n; i++) {
				suma+=md[i].a;
				sumb+=md[i].b;
				sumc+=md[i].c;
				md[i].id=i;
				db[i]=md[i].b-md[i].a;
				dc[i]=md[i].c-md[i].a;
				if(db[i]>dc[i])dd[i]=db[i];
				else dd[i]=dc[i];
			}
			int ct=n/2,bt=0,dt=0;
			if(g(suma,sumb)==1) {
				sort(md+1,md+n+1,cmp2);
				for(int i=1; i<=ct; i++)ans+=md[i].c;
			} else if(g(suma,sumc)==1) {
				sort(md+1,md+n+1,bmp);
				for(int i=1; i<=ct; i++) {
					ans+=md[i].b;
				}
			} else if(g(sumb,sumc)==1) {
				sort(md+1,md+n+1,amp);
				for(int i=1; i<=ct; i++)ans+=md[i].a;
			} else {
				sort(md+1,md+n+1,dmp);
				for(int i=1; i<=n; i++) {
					if(db[i]>0&&dc[i]>0) {
						if(dt<ct) {
							if(db[i]>dc[i])suma+=db[i];
							else suma+=dc[i];
							dt++;
						}
					} else if(db[i]>0) {
						if(dt<ct) {
							dt++;
							suma+=db[i];
						}
					} else if(dc[i]>0) {
						if(dt<ct) {
							dt++;
							suma+=dc[i];
						}
					}//-+ ++
					else {
						if(bt<ct)bt++;
						else {
							if(db[i]>dc[i])suma+=db[i];
							else suma+=db[i];
						}
					}//--
					ans=suma;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
