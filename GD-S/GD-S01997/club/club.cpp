#include<bits/stdc++.h>
using namespace std;
long long t,n,b[100010],k[100010],an,l_add,c_man,man_cbm,w,f[4];
struct w{
	int a,b,c;
}q[100010];
void dfs(int i,long long s,int a1,int b1,int c1){
	an=max(an,s);
	if(i==n)return;
	if(a1!=n/2)dfs(i+1,s+q[i+1].a,a1+1,b1,c1);
	if(b1!=n/2)dfs(i+1,s+q[i+1].b,a1,b1+1,c1);
	if(c1!=n/2)dfs(i+1,s+q[i+1].c,a1,b1,c1+1);
	dfs(i+1,s,a1,b1,c1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>q[i].a>>q[i].b>>q[i].c;
		}
		an=0;
		if(n<=10){
			dfs(0,0,0,0,0);
			cout<<an<<endl;
		}
		else if(n<=200){
			//f:各部门人数 
			//l_add:总价值
			//c_man:更换的前成员 
			//man_cbm: 前成员到达到的位置 
			f[1]=f[2]=f[3]=0;
			for(int i=1;i<=n;i++){
				l_add=c_man=man_cbm=0;
				long long w=4,ma;
				for(int j=1;j<i;j++){
					if(k[j]==1){
						if(f[2]!=n/2){
							if(q[i].a-q[j].a+q[j].b>l_add)l_add=q[i].a-q[j].a+q[j].b,c_man=j,man_cbm=2;
						}
						if(f[3]!=n/2){
							if(q[i].a-q[j].a+q[j].c>l_add)l_add=q[i].a-q[j].a+q[j].c,c_man=j,man_cbm=3;
						}
					}
					if(k[j]==2){
						if(f[1]!=n/2){
							if(q[i].b-q[j].b+q[j].a>l_add)l_add=q[i].b-q[j].b+q[j].a,c_man=j,man_cbm=1;
						}
						if(f[3]!=n/2){
							if(q[i].b-q[j].b+q[j].c>l_add)l_add=q[i].b-q[j].b+q[j].c,c_man=j,man_cbm=3;
						}
					}
					if(k[j]==3){
						if(f[1]!=n/2){
							if(q[i].c-q[j].c+q[j].a>l_add)l_add=q[i].c-q[j].c+q[j].a,c_man=j,man_cbm=1;
						}
						if(f[3]!=n/2){
							if(q[i].c-q[j].c+q[j].b>l_add)l_add=q[i].c-q[j].c+q[j].b,c_man=j,man_cbm=2;
						}
					}
				//	cout<<l_add<<' '<<c_man<<' '<<man_cbm<<' '<<i<<' '<<j<<endl;
				}
				ma=l_add;
				if(f[1]!=n/2){
					if(q[i].a>ma)w=1,ma=q[i].a;
					if(q[i].a==ma){
						if(f[1]<f[man_cbm])w=1,ma=q[i].a;
					}
				}
				if(f[2]!=n/2){
					if(q[i].b>ma)w=2,ma=q[i].b;
					if(q[i].b==ma){
						if(f[2]<f[man_cbm])w=2,ma=q[i].b;
					}
				}
				if(f[3]!=n/2){
					if(q[i].c>ma)w=3,ma=q[i].c;
					if(q[i].c==ma){
						if(f[3]<f[man_cbm])w=3,ma=q[i].c;
					}
				}
				if(ma==0)continue;
				if(w==1)f[1]++,k[i]=1;
				if(w==2)f[2]++,k[i]=2;
				if(w==3)f[3]++,k[i]=3;
				if(w==4)f[man_cbm]++,k[c_man]=man_cbm;
				an+=ma;
			//	cout<<ma<<' '<<an<<' '<<endl;
			}
			cout<<an;
		}
	}
	return 0;
}

