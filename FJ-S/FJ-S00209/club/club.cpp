#include<bits/stdc++.h>

using namespace std;

int T;
int n;
int aa,bb,cc;

struct node{
	int a,b,c;
	int f,ac,ab,bc;
	int book=0;
}q[100005];

bool cmp1(node x,node y){
	return min(x.ab,x.ac)<min(y.ab,y.ac);
}

bool cmp2(node x,node y){
	return min(x.ab,x.bc)<min(x.ab,x.bc);
}

bool cmp3(node x,node y){
	return min(x.bc,x.ac)<min(y.bc,y.ac);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>q[i].a>>q[i].b>>q[i].c;
			q[i].f=max(q[i].a,max(q[i].b,q[i].c));
			if(q[i].f==q[i].a) aa++,q[i].book=1;
			else if(q[i].f==q[i].b) bb++,q[i].book=2;
			else cc++,q[i].book=3;
			q[i].ac=abs(q[i].a-q[i].c),q[i].ab=abs(q[i].a-q[i].b),q[i].bc=abs(q[i].b-q[i].c);
		}	
		int p=n/2;
		int aaa=aa-p,bbb=bb-p,ccc=cc-p;
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=q[i].f;
		if(aa>p){
			sort(q+1,q+1+n,cmp1);
			for(int i=1;i<=aaa;i++){
				if(q[i].book==1){
					ans-=min(q[i].ab,q[i].ac);
					if(q[i].ab>q[i].ac) aa--,cc++;
					else aa--,bb++;
				}else if(q[i].book!=1) aaa++;
			}
		}
		if(bb>p){
			sort(q+1,q+1+n,cmp2);
			for(int i=1;i<=bbb;i++){
				if(q[i].book==2){
					ans-=min(q[i].ab,q[i].bc);
					if(q[i].ab>q[i].bc) bb--,cc++;
					else bb--,aa++;
				}else if(q[i].book!=2) bbb++;
			}
		}	
		if(cc>p){
			sort(q+1,q+1+n,cmp3);
			for(int i=1;i<=ccc;i++){
				if(q[i].book==3){
					ans-=min(q[i].ac,q[i].bc);
					if(q[i].ac>q[i].bc) cc--,bb++;
					else cc--,aa++;
				}else if(q[i].book!=3) ccc++;
			}
		}
		cout<<ans<<'\n';	
		ans=0;
		aa=0,bb=0,cc=0;
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

