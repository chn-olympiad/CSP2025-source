#include<bits/stdc++.h>
using namespace std;
struct zhi{
	int a,b,c;
};

int bcj[1000030];
int zz(int ask){
	if(bcj[ask]==ask){
		return ask;
	}else{
		return bcj[ask]=zz(bcj[ask]);
	}
}
void hb(int a,int b){
	bcj[zz(a)]=zz(b);
}

bool ae1(zhi a,zhi b){
	return a.c<b.c;
}

int vis[1000010];
int cnt=0;
zhi ask[2000000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		bcj[i]=i;
	}
	for(int i=1;i<=m;i+=1){
		cin>>ask[i].a>>ask[i].b>>ask[i].c;
	}
	sort(ask+1,ask+1+n,ae1);
	int cnt=0;
	int an=0;
	for(int i=1;i<=m;i++){
		if(zz(ask[i].a)!=zz(ask[i].b)){
			cnt++;
			an+=ask[i].c;
			hb(ask[i].a,ask[i].b);
			if(cnt==n-1){
				cout<<an;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
