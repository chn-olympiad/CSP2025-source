#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct gp{
	int ur,cd;
};
gp a[N],b[N],c[N];
bool cmp(gp x,gp y){
	return x.cd>y.cd;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T;
	cin>>T;
	while(T--){
		int n,member,sum1=0,sum2=0,sum3=0,ans=0,t=0;
		bool flag[n+1][4];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].cd>>b[i].cd>>c[i].cd;
			a[i].ur=i,b[i].ur=i,c[i].ur=i;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		t=0;
		for(int i=1;i<=n;i++){
			if(n-t==1){ans+=max(max(a[i].cd,b[i].cd),c[i].cd);break;}
			if(n-t==2){
				if(a[i].ur==b[i].ur==c[i].ur){
					int ans1=0,ans2=0,ans3=0,ans4=0,ans5=0,ans6=0;
					ans1=a[i+1].cd+b[i].cd;
					ans2=a[i].cd+b[i+1].cd;
					ans3=a[i].cd+c[i+1].cd;
					ans4=a[i+1].cd+c[i].cd;
					ans5=b[i].cd+c[i+1].cd;
					ans6=b[i+1].cd+c[i].cd;
					ans+=max(ans1,max(ans2,max(ans3,max(ans4,max(ans5,ans6)))));
					break;
				}
				if(a[i].ur==b[i].ur){
					int ans1=0,ans2=0,ans3=0,ans4=0,ans5=0,ans6=0;
					ans1=a[i+1].cd+b[i].cd;
					ans2=a[i].cd+b[i+1].cd;
					ans3=a[i].cd+c[i].cd;
					ans4=a[i+1].cd+c[i].cd;
					ans5=b[i].cd+c[i].cd;
					ans6=b[i+1].cd+c[i].cd;
					ans+=max(ans1,max(ans2,max(ans3,max(ans4,max(ans5,ans6)))));
					break;
				}
				if(a[i].ur==c[i].ur){
					int ans1=0,ans2=0,ans3=0,ans4=0,ans5=0,ans6=0;
					ans1=a[i+1].cd+b[i].cd;
					ans2=a[i].cd+b[i].cd;
					ans3=a[i].cd+c[i].cd;
					ans4=a[i].cd+c[i+1].cd;
					ans5=b[i].cd+c[i].cd;
					ans6=b[i].cd+c[i+1].cd;
					ans+=max(ans1,max(ans2,max(ans3,max(ans4,max(ans5,ans6)))));
					break;
				}
				if(b[i].ur==c[i].ur){
					int ans1=0,ans2=0,ans3=0,ans4=0,ans5=0,ans6=0;
					ans1=a[i].cd+b[i].cd;
					ans2=a[i].cd+b[i+1].cd;
					ans3=a[i].cd+c[i].cd;
					ans4=a[i].cd+c[i+1].cd;
					ans5=b[i].cd+c[i+1].cd;
					ans6=b[i+1].cd+c[i].cd;
					ans+=max(ans1,max(ans2,max(ans3,max(ans4,max(ans5,ans6)))));
					break;	
				}
				int ans1=0,ans2=0,ans3=0;
				ans1=a[i].cd+b[i].cd;
				ans2=a[i].cd+c[i].cd;
				ans3=b[i].cd+c[i].cd;
				ans+=max(ans1,max(ans2,ans3));
				break;
			}
			ans+=a[i].cd+b[i].cd+c[i].cd;
			t+=3;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
