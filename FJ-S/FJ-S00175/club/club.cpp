#include<bits/stdc++.h>
using namespace std;
int t,n,z1,z2,z3,ans,tmp1[500010],tmp4[500010],tmp5[500010];
struct node{
	int a,b,c;
}tmp[500010];
bool ent(node i,node j){
	return i.a+i.b+i.c<j.a+j.b+j.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++){
		cin>>n;
		ans=0;
		memset(tmp,0,sizeof(tmp));
		for (int i=1;i<=n;i++){
			cin>>tmp[i].a>>tmp[i].b>>tmp[i].c;
		}
		sort(tmp+1,tmp+n+1,ent);
		if (tmp[i].b==tmp[i].c&&tmp[i].b==0){
			int tmp2=0;
			for (int x=1;x<=n;x++){
			 	tmp1[x]=tmp[x].a;
			}
			sort(tmp1+1,tmp1+n+1);
			for (int x=n;x>=n/2+1;x--){
				tmp2+=tmp1[x];
			}
			cout<<tmp2<<endl;
			memset(tmp1,0,sizeof(tmp1));
			continue;
		}
		if (tmp[i].c==0){
			int tmp3=0;
			for (int x=1;x<=n;x++){
			 	tmp4[x]=tmp[x].a;
			 	tmp5[x]=tmp[x].b;
			}
			sort(tmp4+1,tmp4+n+1);
			sort(tmp5+1,tmp5+n+1);
			for (int x=n;x>=n/2+1;x--){
				tmp3+=tmp4[x];
				tmp3+=tmp5[x];
			}
			cout<<tmp3<<endl;
			memset(tmp1,0,sizeof(tmp4));
			memset(tmp1,0,sizeof(tmp5));
			continue;
		}
		for (int i=1;i<=n;i++){
			if (tmp[i].b>=tmp[i].a||tmp[i].c>=tmp[i].a){
				if (z2<n/2||z3<n/2){
					if (tmp[i].b>=tmp[i].c&&z2<n/2){
						ans+=tmp[i].b;
						z2++;
					}else{
						ans+=tmp[i].c;
						z3++;
					}
				}else{
					if (z2<n/2){
						ans+=tmp[i].b;
						z2++;
					}else{
						ans+=tmp[i].c;
						z3++;
					}
				}
			}else{
				ans+=tmp[i].a;
				z1++;
				continue;
			}
		}
		cout<<ans;
	} 
	return 0;
}
//max(a[i][j],a[i-1][j-w[i]]+v[i]) 01
