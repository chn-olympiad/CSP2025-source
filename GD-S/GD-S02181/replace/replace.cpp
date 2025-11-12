#include<bits/stdc++.h>
using namespace std;
string t1,t2,x,y;
struct z{
	string s1,s2;
	int sn;
}H[200001];
bool cmp(z x,z y){
	return x.sn<y.sn;
}
bool pd1(int x,int y,int z){
	register bool bj;
	for(register int i=0,j;i<=~-H[x].sn-z+y;++i){
		bj=true;
		for(j=y;j<=z;++j)
			if(t1[j]!=H[x].s1[j-y+i]||t2[j]!=H[x].s2[j-y+i]){
				bj=false;
				break;
			}
		if(bj)
			return true;
	}
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	register int n,q,i,j,h,t,ans=0;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i){
		cin>>H[i].s1>>H[i].s2;
		H[i].sn=H[i].s1.size();
	}
	sort(H+1,H+n+1,cmp);
	while(q--){
		cin>>t1>>t2;
		t=ans=0,h=-1;
		for(j=0;j<t1.size();++j)
			if(t1[j]!=t2[j]){
				if(h==-1)
					h=j;
				t=j;
			}
		for(j=n;j>0;--j){
			if(H[j].sn<-~t-h)break;
			if(pd1(j,h,t))
				++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
