//GZ-S00382 贵阳市第一中学 胡源宸 
#include<bits/stdc++.h>
#define ls 1>>1
#define rs 1>>1|1
using namespace std;
using ll=long long;
constexpr int N=1e5+10;
constexpr int inf=0x3f3f3f3f;
int n;
int fi,se,th;
int ans;
int k;
struct node{
	int fi2,se2,th2,zd,cd,bian,zx,zdcd,cdzx;
}a[N],b[N];
int T;
bool cmp(node x,node y){
	return x.zdcd>y.zdcd;
}
bool cmp2(node x,node y){
	return x.cdzx>y.cdzx;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		fi=se=th=n/2;
		ans=0;
		k=0;
		for(int i=1;i<=n;i++){
			a[i].bian=0;
			scanf("%d%d%d",&a[i].fi2,&a[i].se2,&a[i].th2);
			if(a[i].fi2>=a[i].se2){
				if(a[i].fi2>=a[i].th2){
					a[i].zd=1;
					if(a[i].se2>=a[i].th2){
						a[i].cd=2;
						a[i].zx=3;
						a[i].zdcd=a[i].fi2-a[i].se2;
						a[i].cdzx=a[i].se2-a[i].th2;
					}else{
						a[i].zx=2;
						a[i].cd=3;
						a[i].zdcd=a[i].fi2-a[i].th2;
						a[i].cdzx=a[i].th2-a[i].se2;
					}
				}else{
					a[i].zd=3;
					a[i].cd=1;
					a[i].zx=2;
					a[i].zdcd=a[i].th2-a[i].fi2;
					a[i].cdzx=a[i].fi2-a[i].se2;
				}
			} else{
				if(a[i].se2>=a[i].th2){
					a[i].zd=2;
					if(a[i].fi2>=a[i].th2){
						a[i].cd=1;
						a[i].zx=3;
						a[i].zdcd=a[i].se2-a[i].fi2;
						a[i].cdzx=a[i].fi2-a[i].th2;
					}else{
						a[i].zx=1;
						a[i].cd=3;
						a[i].zdcd=a[i].se2-a[i].th2;
						a[i].cdzx=a[i].th2-a[i].fi2;
					}
				}else{
					a[i].zd=3;
					a[i].cd=2;
					a[i].zx=1;
					a[i].zdcd=a[i].th2-a[i].se2;
					a[i].cdzx=a[i].se2-a[i].fi2;
				}
			}
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].zd==1){
				if(fi){
					fi--;
					ans+=a[i].fi2;
				}
				else a[i].bian=i;
			}
			if(a[i].zd==2){
				if(se){
					se--;
					ans+=a[i].se2;
				} 
				else a[i].bian=i;
			}
			if(a[i].zd==3){
				if(th){
					th--;
					ans+=a[i].th2;
				} 
				else a[i].bian=i;
			}
			if(a[i].bian==i){
				b[++k]={a[i].fi2,a[i].se2,a[i].th2,a[i].zd,a[i].cd,a[i].bian,a[i].zx};
			}
		}
		for(int i=1;i<=k;i++){
			if(b[i].cd==1){
				ans+=b[i].fi2;
			}
			if(b[i].cd==2){
				ans+=b[i].se2;
			}
			if(b[i].cd==3){
				ans+=b[i].th2;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
