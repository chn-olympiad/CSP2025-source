#include <bits/stdc++.h>
using namespace std;
long long a,c=0,d[100005],e;
bool f[100005];
struct aa{
	long long a,b,c,d,e,f;
}b[100005];
bool cmp(aa g,aa h){
	if(g.d==h.d){
		return g.e>h.e;
	}
	return g.d>h.d;
}
void dfs(long long g,long long l,long long m,long long n){
	for(int z=1;z<=a;z++){
		if(f[z]==1)continue;
		f[z]=1;
		if(l<e){
			dfs(g+b[z].a,l+1,m,n);
		}
		if(m<e){
			dfs(g+b[z].b,l,m+1,n);
		}
		if(n<e){
			dfs(g+b[z].c,l,m,n+1);
		}
		f[z]=0;
	}
	c=max(c,g);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int A;
	cin>>A;
	while(A--){
		cin>>a;
		c=0;
		e=a/2;
		for(int z=1;z<=a;z++){
			cin>>b[z].a>>b[z].b>>b[z].c;
			b[z].e=b[z].a+b[z].b+b[z].c;
			b[z].d=max(b[z].a,max(b[z].b,b[z].c));
			if(b[z].a==b[z].d)b[z].f=1;
			if(b[z].b==b[z].d)b[z].f=2;
			if(b[z].c==b[z].d)b[z].f=3;
		}
		sort(b+1,b+1+a,cmp);
		if(a<=4){
			dfs(0,0,0,0);
		}
		else{
			for(int z=1;z<=e;z++)c+=b[z].a;
		}
		cout<<c<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
