#include <bits/stdc++.h>
using namespace std;
long long n,m,k,c[15],f[15005],d[15][10005],zym,aa,bb,t,kkk;
bool spe1=true,spe2;
struct somebody{
	long long a,b,c;
};
somebody s[1500005],p[1500005];
bool cmp(somebody a,somebody b){
	return a.c<b.c;
}
long long find(long long o){
	if(f[o]==o){
		return o;
	}
	else{
		return f[o]=find(f[o]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	*cin.tie(nullptr)<<fixed<<setprecision(20);
	cout.tie(nullptr)->ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			spe1=false;
		}
		spe2=false;
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
			if(d[i][j]==0){
				spe2=true;	
			}
		}
		if(spe2==false){
			spe1==true;
		}
	}
	if(k==0){
		sort(s+1,s+1+m,cmp);
		for(int i=1;i<=m;i++){
			aa=find(s[i].a);
			bb=find(s[i].b);
			if(aa!=bb){
				f[aa]=bb;
				zym+=s[i].c;
			}
		}
		cout<<zym;
	}
	else if(spe1==true){
		for(int i=1;i<=k;i++){
			f[n+i]=n+i;
			for(int j=1;j<=n;j++){
				m++;
				s[m].a=n+i;
				s[m].b=j;
				s[m].c=d[i][j];
			}
		}
		sort(s+1,s+1+m,cmp);
		for(int i=1;i<=m;i++){
			aa=find(s[i].a);
			bb=find(s[i].b);
			if(aa!=bb){
				f[aa]=bb;
				zym+=s[i].c;
			}
		}
		cout<<zym;
	}
	else{
		zym=114514114514;
		for(int ss=(1<<k)-1;ss>=0;ss--){
			t=m;
			for(int i=1;i<=m;i++){
				p[i].a=s[i].a;
				p[i].b=s[i].b;
				p[i].c=s[i].c;
			}			
			for(int i=1;i<=n;i++){
				f[i]=i;
			}
			kkk=0;
			for(int i=1;i<=k;i++){
				if(((ss>>(i-1))&1)==1){
					f[n+i]=n+i;
					kkk+=c[i];
					for(int j=1;j<=n;j++){
						t++;
						p[t].a=n+i;
						p[t].b=j;
						p[t].c=d[i][j];
					}
				}
			}
			sort(p+1,p+1+t,cmp);
			for(int i=1;i<=t;i++){
				aa=find(p[i].a);
				bb=find(p[i].b);
				if(aa!=bb){
					f[aa]=bb;
					kkk+=p[i].c;
				}
			}
			zym=min(zym,kkk);
		}
		cout<<zym;
	}
	return 0;
}
