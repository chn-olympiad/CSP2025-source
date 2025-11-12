//GZ-S00363 毕节梁才学校 罗悦辉
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int T,n;
int x,y,z;

struct OP {
	int yi,er,san;
} d[100000+10];
OP dd;

LL ans;

bool cmpa(OP a,OP b) {
	return a.yi>b.yi;
}

int aa[10],idxd;
vector<OP> vct[10];

bool cmpz(OP a,OP b) {
	aa[1]=a.er,aa[2]=a.san,aa[3]=a.yi;
	sort(aa+1,aa+3+1);
	int r=aa[3]-aa[2];
	aa[1]=b.er,aa[2]=b.san,aa[3]=b.yi;
	sort(aa+1,aa+3+1);
	int t=aa[3]-aa[2];
	return r<t;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	scanf("%d",&T);
	while(T--) {

		ans=0;
		idxd=0;
		vct[1].clear();
		vct[2].clear();
		vct[3].clear();

		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&x,&y,&z);
			d[i]=(OP) {
				x,y,z
			};

		}
		
		for(int i=1; i<=n; i++) {
			x=d[i].yi,y=d[i].er,z=d[i].san;
			aa[1]=x,aa[2]=y,aa[3]=z;
			sort(aa+1,aa+3+1);
			if(aa[3]==x) vct[1].push_back(d[i]);
			else if(aa[3]==y) vct[2].push_back(d[i]);
			else vct[3].push_back(d[i]);
			ans+=aa[3];
		}

		if((int)vct[1].size()>n/2) {
			sort(vct[1].begin(),vct[1].end(),cmpz);
			idxd=1;
		}
		if((int)vct[2].size()>n/2){
			sort(vct[2].begin(),vct[2].end(),cmpz);
			idxd=2;
		} 
		if((int)vct[3].size()>n/2){
			sort(vct[3].begin(),vct[3].end(),cmpz);
			idxd=3;
		} 

		if(idxd==0) {
			printf("%lld\n",ans);
			continue;
		}

		for(int i=0; i<(int)vct[idxd].size()-n/2; i++) {
			dd=vct[idxd][i];
			x=dd.yi,y=dd.er,z=dd.san;
			aa[1]=x,aa[2]=y,aa[3]=z;
			sort(aa+1,aa+3+1);
			ans-=aa[3];
			ans+=aa[2];
		}

		printf("%lld\n",ans);

	}

	return 0;
}
