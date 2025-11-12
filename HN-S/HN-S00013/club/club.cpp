#include <bits/stdc++.h>
using namespace std;
struct data{
	int A,B,C;
}a[100005];
int q1[100005],q2[100005],q3[100005],tot1,tot2,tot3;
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0; 
		cin>>n;
		tot1=0;
		tot2=0;
		tot3=0;
		for(int i=1;i<=n;i++){
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
			a[i].A=a1;
			a[i].B=a2;
			a[i].C=a3;
			if(a1>=a2&&a1>=a3){
				q1[++tot1]=min(a1-a2,a1-a3);
				ans+=a1;
			}else if(a2>=a1&&a2>=a3){
				q2[++tot2]=min(a2-a1,a2-a3);
				ans+=a2;
			}else{
				q3[++tot3]=min(a3-a2,a3-a1);
				ans+=a3;
			}
		}
		if(tot1>n/2){
			sort(q1+1,q1+1+tot1);
			for(int i=1;i<=tot1-n/2;i++){
				ans-=q1[i];
			}
		}else if(tot2>n/2){
			sort(q2+1,q2+1+tot2);
			for(int i=1;i<=tot2-n/2;i++){
				ans-=q2[i];
			}
		}else if(tot3>n/2){
			sort(q3+1,q3+1+tot3);
			for(int i=1;i<=tot3-n/2;i++){
				ans-=q3[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
