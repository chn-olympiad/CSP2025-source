#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,ans,cu1[N],cu2[N],cu3[N],cnt1,cnt2,cnt3;
struct vxxv{
	int cl1,cl2,cl3,ch,maxx;
}a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		ans=0;
		cnt1=cnt2=cnt3=0;
		memset(cu1,0,sizeof(cu1));
		memset(cu2,0,sizeof(cu2));
		memset(cu3,0,sizeof(cu3));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].cl1,&a[i].cl2,&a[i].cl3);
			if(a[i].cl1>a[i].cl2){
				if(a[i].cl1>a[i].cl3){
					a[i].maxx=a[i].cl1;
					a[i].ch=a[i].maxx-max(a[i].cl2,a[i].cl3);
				}else{
					a[i].maxx=a[i].cl3;
					a[i].ch=a[i].maxx-max(a[i].cl2,a[i].cl1);
				}
			}else{
				if(a[i].cl2>a[i].cl3){
					a[i].maxx=a[i].cl2;
					a[i].ch=a[i].maxx-max(a[i].cl1,a[i].cl3);
				}else{
					a[i].maxx=a[i].cl3;
					a[i].ch=a[i].maxx-max(a[i].cl2,a[i].cl1);
				}
			}
			ans+=a[i].maxx;
			if(a[i].maxx==a[i].cl1) cu1[++cnt1]=a[i].ch;
			if(a[i].maxx==a[i].cl2) cu2[++cnt2]=a[i].ch;
			if(a[i].maxx==a[i].cl3) cu3[++cnt3]=a[i].ch;
		}
		if(cnt1>n/2){
			sort(cu1+1,cu1+cnt1+1,cmp);
			while(cnt1>n/2){
				ans-=cu1[cnt1];
				cnt1--;
			}
		}
		if(cnt2>n/2){
			sort(cu2+1,cu2+cnt2+1,cmp);
			while(cnt2>n/2){
				ans-=cu2[cnt2];
				cnt2--;
			}
		}
		if(cnt3>n/2){
			sort(cu3+1,cu3+cnt3+1,cmp);
			while(cnt3>n/2){
				ans-=cu3[cnt3];
				cnt3--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
