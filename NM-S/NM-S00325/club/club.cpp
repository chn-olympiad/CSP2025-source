#include<bits/stdc++.h>
using namespace std;
int t,ma,n,a[7];
long long jg;
struct st{
	int a,b,c;
	int pe,mi,px;
}m[1000007];
bool cmp(st x,st y){
	return x.mi>y.mi;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;for(int tt=1;tt<=t;tt++){
	ma=-1;memset(m,0,sizeof(m));memset(a,0,sizeof(a));jg=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&m[i].a,&m[i].b,&m[i].c);
		m[i].pe=max(m[i].a,max(m[i].b,m[i].c));
		if(m[i].pe==m[i].a){
			m[i].mi=m[i].pe-max(m[i].b,m[i].c);a[1]++;m[i].px=1;
		}else if(m[i].pe==m[i].b){
			m[i].mi=m[i].pe-max(m[i].a,m[i].c);a[2]++;m[i].px=2;
		}else{
			m[i].mi=m[i].pe-max(m[i].a,m[i].b);a[3]++;m[i].px=3;
		}
	}sort(m+1,m+n+1,cmp);
	int am=max(a[1],max(a[2],a[3]));
	int z=0;if(am==a[1])z=1;
	else if(am==a[2])z=2;
	else if(am==a[3])z=3;
	if(am*2<=n)am=0;
	else am-=n/2;
	for(int i=n,j=1;i>=1;i--){
		if(j<=am){
			if(m[i].px==z){
				jg+=m[i].pe-m[i].mi;j++;
			}
			else{
				jg+=m[i].pe;
			}
		}
		else jg+=m[i].pe;
	}cout<<jg<<endl;
	}return 0;
}
