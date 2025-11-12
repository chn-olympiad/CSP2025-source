#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
struct P{
	string a;
	string b;
	int za;
	int ya;
	int zb;
	int yb;
}qu[200010],k[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>k[i].a>>k[i].b;
	}
	for(int i=1;i<=q;i++){
		cin>>qu[i].a>>qu[i].b;
		if(qu[i].a.size()!=qu[i].b.size()){
			cout<<0<<endl;
		}
	}
	for(int i=1;i<=q;i++){
		int l=0;
		for(int j=0;j<qu[i].a.size();j++){
			if(qu[i].a[j]=='b'){
				qu[i].za=l;
				qu[i].ya=qu[i].a.size()-l-1;
			}
			l++;
		}
		l=0;
		for(int j=0;j<qu[i].b.size();j++){
			if(qu[i].b[j]=='b'){
				qu[i].zb=l;
				qu[i].yb=qu[i].b.size()-l-1;
			}
			l++;
		}
	}
	for(int i=1;i<=n;i++){
		int l=0;
		for(int j=0;j<k[i].a.size();j++){
			if(k[i].a[j]=='b'){
				k[i].za=l;
				k[i].ya=k[i].a.size()-l-1;
			}
			l++;
		}
		l=0;
		for(int j=0;j<k[i].b.size();j++){
			if(k[i].b[j]=='b'){
				k[i].zb=l;
				k[i].yb=k[i].b.size()-l-1;
			}
			l++;
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++){
			if(qu[i].za+k[j].zb==qu[i].zb+k[j].za&&qu[i].ya+k[j].yb==qu[i].yb+k[j].ya){
				ans++;
			}
		}cout<<ans<<endl;
	}
	
	return 0;
}
//GIVE ME 5 POINTS!!!
