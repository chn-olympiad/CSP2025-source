#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][3],ans,top1,top2,top3,t1,t2,t3;
int q1[100001],q2[100001],q3[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0,top1=0,top2=0,top3=0;
		for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int i=1;i<=n;i++){
			int x=a[i][0],y=a[i][1],z=a[i][2];
			if(x>=y){
				if(x>=z) q1[++top1]=x-max(y,z);
				else q3[++top3]=z-x;
			}else{
				if(y>=z) q2[++top2]=y-max(x,z);
				else q3[++top3]=z-y;
			}
			ans+=max(x,max(y,z));
		}
		sort(q1+1,q1+top1+1);
		sort(q2+1,q2+top2+1);
		sort(q3+1,q3+top3+1);
		t1=top1,t2=top2,t3=top3;
		while(top1>n/2){
			ans-=q1[t1-top1+1];
			top1--;
		}
		while(top2>n/2){
			ans-=q2[t2-top2+1];
			top2--;
		}
		while(top3>n/2){
			ans-=q3[t3-top3+1];
			top3--;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

