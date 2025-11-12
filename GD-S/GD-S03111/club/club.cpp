#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int p,q,n,d,e,g,sum;
struct rty{
	int a,b,c;
}f[N];
bool cmp(rty x,rty y){
	return max(max(x.a,x.b),x.c)>max(max(y.a,y.b),y.c);
}
bool cmpa(rty x,rty y){
	return max(x.b,x.c)>max(y.b,y.c);
}
bool cmpc(rty x,rty y){
	return max(x.b,x.a)>max(y.b,y.a);
}
bool cmpb(rty x,rty y){
	return max(x.a,x.c)>max(y.a,y.c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>q;
	while(q--){
		d=e=g=sum=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>f[i].a>>f[i].b>>f[i].c;
		sort(f+1,f+n+1,cmp);
		for(p=1;p<=n;p++){
			if(f[p].a>f[p].b&&f[p].a>f[p].c)
				sum+=f[p].a,d++;
			else if(f[p].b>f[p].a&&f[p].b>f[p].c)
				sum+=f[p].b,e++;
			else sum+=f[p].c,g++;
			if(d==(n>>1)||e==(n>>1)||g==(n>>1)) break;
		}
		p++;
		if(d==(n>>1)){
			sort(f+p,f+n+1,cmpa);
			for(;p<=n;p++){
				if(f[p].b>f[p].c)
					sum+=f[p].b;
				else sum+=f[p].c;
			}
		}
		else if(e==(n>>1)){
			sort(f+p,f+n+1,cmpb);
			for(;p<=n;p++){
				if(f[p].a>f[p].c)
					sum+=f[p].a;
				else sum+=f[p].c;
			}
		}
		else{
			sort(f+p,f+n+1,cmpc);
			for(;p<=n;p++){
				if(f[p].a>f[p].b)
					sum+=f[p].a;
				else sum+=f[p].b;
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
