#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int T;
int n;
int fav[maxn];
struct member{
	int a,b,c;
}m[maxn];
struct mF{
	int a,b,c;
	friend bool operator<(mF x,mF y){
		return x.a+max(x.b,x.c)>y.a+max(x.b,x.c);
	}
};
struct mS{
	int a,b,c;
	friend bool operator<(mS x,mS y){
		return x.b+max(x.a,x.c)>y.b+max(x.a,x.c);
	}
};
struct mT{
	int a,b,c;
	friend bool operator<(mT x,mT y){
		return x.c+max(x.a,x.b)>y.c+max(x.a,x.b);
	}
};
priority_queue<mF>f;
priority_queue<mS>s;
priority_queue<mT>t;
int ansf,anss,anst;
int cntf,cnts,cntt;
void add(int type,member val){
	switch(type){
		case 1:
			f.push({val.a,val.b,val.c});
			ansf+=val.a;
			cntf++;
			break;
		case 2:
			s.push({val.a,val.b,val.c});
			anss+=val.b;
			cnts++;
			break;
		case 3:
			t.push({val.a,val.b,val.c});
			anst+=val.c;
			cntt++;
			break;
	}
}
int ans,vmax[3];
void back(int i,int cnt,int cf,int cs,int ct){
	if(i==n+1){
		ans=max(ans,cnt);
		return ;
	}
	if(cf<n/2&&cnt+m[i].a+vmax[0]*(n-i)>=ans)back(i+1,cnt+m[i].a,cf+1,cs,ct);
	if(cs<n/2&&cnt+m[i].b+vmax[1]*(n-i)>=ans)back(i+1,cnt+m[i].b,cf,cs+1,ct);
	if(ct<n/2&&cnt+m[i].c+vmax[2]*(n-i)>=ans)back(i+1,cnt+m[i].c,cf,cs,ct+1);
}
bool cmp(member x,member y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		while(!f.empty())f.pop();
		while(!s.empty())s.pop();
		while(!t.empty())t.pop();
		ans=ansf=anss=anst=0;
		cntf=cnts=cntt=0;
		memset(fav,0,sizeof(fav));
		cin>>n;bool flagA=true;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			vmax[0]=max(vmax[0],m[i].a);
			vmax[1]=max(vmax[1],m[i].b);
			vmax[2]=max(vmax[2],m[i].c);
			flagA=flagA&&m[i].b==0&&m[i].c==0;
			if(m[i].a>=m[i].b&&m[i].a>=m[i].c)fav[i]=1;
			else if(m[i].b>=m[i].a&&m[i].b>=m[i].c)fav[i]=2;
			else if(m[i].c>=m[i].a&&m[i].c>=m[i].b)fav[i]=3;
		}if(flagA){
			sort(m+1,m+n+1,cmp);
			for(int i=1;i<=n/2;i++)ans+=m[i].a;
			cout<<ans<<'\n';
			continue;
		}if(n<=10){
			back(1,0,0,0,0);
			cout<<ans<<'\n';
			continue;
		}for(int i=1;i<=n;i++){
			member p=m[i];
			switch(fav[i]){
				case 1:
					if(f.empty())add(1,p);
					else if(cntf==n/2){
						if(-f.top().a+p.a+max(f.top().b,f.top().c)>max(p.b,p.c)){
							member tmp={f.top().a,f.top().b,f.top().c};
							ansf-=f.top().a;
							f.pop();
							cntf--;
							add(1,p);
							if(tmp.b>=tmp.c)add(2,tmp);
							else add(3,tmp);
						}else{
							if(p.b>=p.c)add(2,p);
							else add(3,p);
						}
					}else add(1,p);
					break;
				case 2:
					if(s.empty())add(2,p);
					else if(cnts==n/2){
						if(-s.top().b+p.b+max(s.top().a,s.top().c)>max(p.c,p.a)){
							member tmp={s.top().a,s.top().b,s.top().c};
							anss-=s.top().b;
							s.pop();
							cnts--;
							add(2,p);
							if(tmp.c>=tmp.a)add(3,tmp);
							else add(1,tmp);
						}else{
							if(p.c>=p.a)add(3,p);
							else add(1,p);
						}
					}else add(2,p);
					break;
				case 3:
					if(t.empty())add(3,p);
					else if(cntt==n/2){
						if(-t.top().c+p.c+max(t.top().a,t.top().b)>max(p.a,p.b)){
							member tmp={t.top().a,t.top().b,t.top().c};
							anst-=t.top().c;
							t.pop();
							cntt--;
							add(3,p);
							if(tmp.a>=tmp.b)add(1,tmp);
							else add(2,tmp);
						}else{
							if(p.a>=p.b)add(1,p);
							else add(2,p);
						}
					}else add(3,p);
					break;
			}
		}cout<<ansf+anss+anst<<'\n';
	}
	return 0;
}

