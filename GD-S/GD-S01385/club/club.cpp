#include <bits/stdc++.h>
using namespace std; //写这么多得给个努力分吧 o(╥﹏╥)o 
int t,n,to[3],t1[100005],t2[100005],t3[100005],cnt1,cnt2,cnt3,ans;
struct node{
	int a,b,c,m1,m2,m3,m11,m22,m33;
}p[100005];
bool cmp(node x,node y){
	if(x.m1!=y.m1)
		return x.m1>y.m1;
	else if(x.m2!=y.m2)
		return x.m2>y.m2;
	return x.m3>y.m3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=cnt1=cnt2=cnt3=0;
		memset(to,0,sizeof(to));
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		memset(t3,0,sizeof(t3));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			p[i].m1=max(p[i].a,max(p[i].b,p[i].c));
			p[i].m3=min(p[i].a,min(p[i].b,p[i].c));
			if(p[i].a<=p[i].m1&&p[i].a>=p[i].m3){
				p[i].m2=p[i].a;
				p[i].m22=1;
			}
			else if(p[i].b<=p[i].m1&&p[i].b>=p[i].m3){
				p[i].m2=p[i].b;
				p[i].m22=2;
			}
			else{
				p[i].m2=p[i].c;
				p[i].m22=3;
			}
			if(p[i].m1==p[i].a)
				p[i].m11=1;
			else if(p[i].m1==p[i].b)
				p[i].m11=2;
			else
				p[i].m11=3;
			p[i].m33=6-p[i].m11-p[i].m22;
		}	
		sort(p+1,p+n+1,cmp);
		to[2]=to[1]=to[0]=n/2;
		for(int i=1;i<=n;i++){
			if(to[p[i].m11]>0){
				to[p[i].m11]--;
				t1[++cnt1]=p[i].m1;
			}
			else{
				sort(t1+1,t1+cnt1+1);
				if(p[i].m1>t1[1]){
					t1[1]=p[i].m1;//
				}
				else{
					if(to[p[i].m22]>0){
						to[p[i].m22]--;
						t2[++cnt2]=p[i].m2;
					}
					else{
						sort(t2+1,t2+cnt2+1);
						if(p[i].m2>t2[1]){
							t2[1]=p[i].m2;//
						}
						else{
							if(to[p[i].m33]>0){
								to[p[i].m33]--;
								t3[++cnt3]=p[i].m3;
							}
							else{
								sort(t3+1,t3+cnt3+1);
								t3[1]=p[i].m3;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=cnt1;i++)
			ans+=t1[i];
		for(int i=1;i<=cnt2;i++)
			ans+=t2[i];	
		for(int i=1;i<=cnt3;i++)
			ans+=t3[i];
		cout<<ans<<"\n";
	}
	return 0;
} 
