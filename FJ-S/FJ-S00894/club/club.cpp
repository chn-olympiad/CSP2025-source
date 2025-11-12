#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int t,n,a[MAXN][4],hn;
int q1[MAXN],q2[MAXN],q3[MAXN],cnt1,cnt2,cnt3,tot1,tot2,tot3,tot;
bool cmp1(int xt1,int xt2){return (max(a[xt1][2],a[xt1][3])-a[xt1][1])>(max(a[xt2][2],a[xt2][3])-a[xt2][1]);}
bool cmp2(int xt1,int xt2){return (max(a[xt1][1],a[xt1][3])-a[xt1][2])>(max(a[xt2][1],a[xt2][3])-a[xt2][2]);}
bool cmp3(int xt1,int xt2){return (max(a[xt1][2],a[xt1][1])-a[xt1][3])>(max(a[xt2][2],a[xt2][1])-a[xt2][3]);}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		tot=0;tot1=0;tot2=0;tot3=0;
		cnt1=0;cnt2=0;cnt3=0;
		cin>>n;hn=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<4;j++){
				cin>>a[i][j];
			}
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				q1[++cnt1]=i;tot1+=a[i][1];
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				q2[++cnt2]=i;tot2+=a[i][2];
			}
			else{
				q3[++cnt3]=i;tot3+=a[i][3];
			}
		}
/*		cout<<tot1<<" "<<tot2<<" "<<tot3<<endl;
		cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;*/
		tot=tot1+tot2+tot3;
		if(cnt1>hn){
			sort(q1+1,q1+1+cnt1,cmp1);
			for(int i=1;i<=cnt1-hn;i++){
				tot+=max(a[q1[i]][2],a[q1[i]][3])-a[q1[i]][1];
			}
		}
		if(cnt2>hn){
			sort(q2+1,q2+1+cnt2,cmp2);
			for(int i=1;i<=cnt2-hn;i++){
				tot+=max(a[q2[i]][1],a[q2[i]][3])-a[q2[i]][2];
			}
		}
		if(cnt3>hn){
			sort(q3+1,q3+1+cnt3,cmp3);
			for(int i=1;i<=cnt3-hn;i++){
				tot+=max(a[q3[i]][2],a[q3[i]][1])-a[q3[i]][3];
			}
		}
		cout<<tot<<endl;
	}
	return 0;
}
