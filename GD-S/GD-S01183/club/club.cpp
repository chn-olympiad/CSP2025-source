#include<bits/stdc++.h>
using namespace std;
struct nd{
	int s1,s2,s3;
}a[100005];
bool cmp1(nd x,nd y){
	return x.s1<y.s1;
}
bool cmp2(nd x,nd y){
	return x.s1-x.s2<y.s1-y.s2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;cin>>n;
	if(n==2){
		int a[4],b[4];
		cin>>a[1]>>a[2]>>a[3]>>b[1]>>b[2]>>b[3];
		int mx1=0,sec1=0,id1=0,mx2=0,sec2=0,id2=0;
		for(int i=1;i<=3;i++){
			if(a[i]>mx1){
				sec1=mx1;
				mx1=a[i],id1=i;
			}
			else if(a[i]>sec1){
				sec1=a[i];
			}
			if(b[i]>mx2){
				sec2=mx2;
				mx2=b[i],id2=i;
			}else if(b[i]>sec2) sec2=b[i];
		}
		if(id1!=id2) cout<<mx1+mx2;
		else{
			cout<<max(mx1+sec2,mx2+sec1);
		}
	}
	else{
		bool flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			if(a[i].s2!=0) flag1=0;
			if(a[i].s3!=0) flag2=0;
		}
		if(flag1&&flag2){
			int ans=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=n;i>n/2;i--){
				ans+=a[i].s1;
			}
			cout<<ans;
		}
		else if(flag2){
			int ans1=0,ans2=0;
			for(int i=n;i>0;i--){
				ans1+=a[i].s1;
			}
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++){
				ans1+=a[i].s2-a[i].s1;
			}
			cout<<ans1;
		}
	}
    return 0;
}

