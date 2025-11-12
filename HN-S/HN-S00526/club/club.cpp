#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int t,n,ans;
struct qwe{
	int a1,a2,a3;
	int ch;
}a[N];
int f1[N],f2[N],f3[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		int flag1=0,flag2=0,flag3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){
				f1[++flag1]=i;
				a[i].ch=min(a[i].a1-a[i].a2,a[i].a1-a[i].a3);
				ans+=a[i].a1;
			}else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3){
				f2[++flag2]=i;
				a[i].ch=min(a[i].a2-a[i].a1,a[i].a2-a[i].a3);
				ans+=a[i].a2;
			}else{
				f3[++flag3]=i;
				a[i].ch=min(a[i].a3-a[i].a1,a[i].a3-a[i].a2);
				ans+=a[i].a3;
			}
		}
		if(flag1>(n/2)){
			for(int i=1;i<=flag1;i++){
				for(int j=i+1;j<=flag1;j++){
					if(a[f1[i]].ch>a[f1[j]].ch){
						int c=f1[i];
						f1[i]=f1[j];
						f1[j]=c;
					}
				}
			}
			for(int i=1;i<=flag1-(n/2);i++){
				ans-=a[f1[i]].ch;
			}
		}else if(flag2>(n/2)){
			for(int i=1;i<=flag2;i++){
				for(int j=i+1;j<=flag2;j++){
					if(a[f2[i]].ch>a[f2[j]].ch){
						int c=f2[i];
						f2[i]=f2[j];
						f2[j]=c;
					}
				}
			}
			for(int i=1;i<=flag2-(n/2);i++){
				ans-=a[f2[i]].ch;
			}
		}else if(flag3>(n/2)){
			for(int i=1;i<=flag3;i++){
				for(int j=i+1;j<=flag3;j++){
					if(a[f3[i]].ch>a[f3[j]].ch){
						int c=f3[i];
						f3[i]=f3[j];
						f3[j]=c;
					}
				}
			}
			for(int i=1;i<=flag3-(n/2);i++){
				ans-=a[f3[i]].ch;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
