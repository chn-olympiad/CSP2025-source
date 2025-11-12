#include<bits/stdc++.h>
using namespace std;
int t,n,su,a1[100005],a2[100005],a3[100005];
void dt(int ahm,int bhm,int chm,int jiazhi,int where) {
	su=max(su,jiazhi);
	if(where>n)return;
	if(ahm<n/2)dt(ahm+1,bhm,chm,jiazhi+a1[where],where+1);
	if(bhm<n/2)dt(ahm,bhm+1,chm,jiazhi+a2[where],where+1);
	if(chm<n/2)dt(ahm,bhm,chm+1,jiazhi+a3[where],where+1);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
		su=0;
		dt(0,0,0,0,1);
		printf("%d\n",su);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


