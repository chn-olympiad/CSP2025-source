#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace  qhx{
	int t,n,idx,idx3,idx2;
	struct node{
		int a;
		int b;
		int c;
	}x[100005],y[100005],z[100005];
	bool cmp(node aa,node bb){
		if(aa.a-max(aa.b,aa.c)!=bb.a-max(bb.b,bb.c)){
			return aa.a-max(aa.b,aa.c)>bb.a-max(bb.b,bb.c);
		}
		return aa.a>bb.a;
	}
	bool cmp2(node aa,node bb){
		if(aa.b-max(aa.a,aa.c)!=bb.b-max(bb.a,bb.c)){
			return aa.b-max(aa.a,aa.c)>bb.b-max(bb.a,bb.c);
		}
		return aa.b>bb.b;
	}
	bool cmp3(node aa,node bb){
		if(aa.c-max(aa.a,aa.b)!=bb.c-max(bb.a,bb.b)){
			return aa.c-max(aa.a,aa.b)>bb.c-max(bb.a,bb.b);
		}
		return aa.b>bb.b;
	}
	void check(){
		sort(x+1,x+1+idx,cmp);
		for(int i=idx;i>n/2;i--){
			if(x[i].b>x[i].c){
				y[++idx2].a=x[i].a;
				y[idx2].b=x[i].b;
				y[idx2].c=x[i].c;
			}
			else{
				z[++idx3].a=x[i].a;
				z[idx3].b=x[i].b;
				z[idx3].c=x[i].c;
			}
			idx--;
		}
		return;
	}
	void check2(){
		sort(y+1,y+1+idx2,cmp2);
		for(int i=idx2;i>n/2;i--){
			if(y[i].a>y[i].c){
				x[++idx].a=y[i].a;
				x[idx].b=y[i].b;
				x[idx].c=y[i].c;
			}
			else{
				z[++idx3].a=y[i].a;
				z[idx3].b=y[i].b;
				z[idx3].c=y[i].c;
			}
			idx2--;
		}
		return;
	}
	void check3(){
		sort(z+1,z+1+idx3,cmp3);
		for(int i=idx3;i>n/2;i--){
			if(z[i].a>z[i].b){
				x[++idx].a=z[i].a;
				x[idx].b=z[i].b;
				x[idx].c=z[i].c;
			}
			else{
				y[++idx2].a=z[i].a;
				y[idx2].b=z[i].b;
				y[idx2].c=z[i].c;
			}
			idx3--;
		}
		return;
	}
	signed main(){
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		cin>>t;
		while(t--){
			cin>>n;
			idx=idx2=idx3=0;
			for(int i=1;i<=n;i++){
				int xx,yy,zz;
				cin>>xx>>yy>>zz;
				if(max(xx,max(yy,zz))==xx){
					x[++idx].a=xx;
					x[idx].b=yy;
					x[idx].c=zz; 
				}
				else if(max(xx,max(yy,zz))==yy){
					y[++idx2].a=xx;
					y[idx2].b=yy;
					y[idx2].c=zz; 
				}
				else if(max(xx,max(yy,zz))==zz){
					z[++idx3].a=xx;
					z[idx3].b=yy;
					z[idx3].c=zz; 
				}
			}
			if(idx>(n/2)){
				check();
			}
			if(idx2>(n/2)){
				check2();
			}
			if(idx3>(n/2)){
				check3();
			}
			int cnt=0;
			for(int i=1;i<=idx;i++){
				cnt+=x[i].a;
			}
			for(int i=1;i<=idx2;i++){
				cnt+=y[i].b;
			}
			for(int i=1;i<=idx3;i++){
				cnt+=z[i].c;
			}
			cout<<cnt<<'\n';
		}
		return 0;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	qhx::main();
	return 0;
}
