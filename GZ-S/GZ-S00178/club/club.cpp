//GZ-S00178 贵阳市华师一学校 张金畅
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct stus{
	int a1,a2,a3,d;
}a[N];
int t,n,ans[N];
bool f[N],f2,f3;
bool cmp1(stus a,stus b){
	return a.a1>b.a1;
}
bool cmp2(stus a,stus b){
	return a.d>b.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		int cnt1=0,cnt2=0,cnt3=0;
		int sum1=0,sum2=0,sum3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].d=a[i].a1-a[i].a2;
			if(a[i].a2!=0)f2=true;
			if(a[i].a3!=0)f3=true;
		}
		if(!f2&&!f3){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				sum1+=a[i].a1;
			}
			cout<<sum1<<endl;
		}else if(!f3){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++)sum1+=a[i].a1;
			for(int i=n/2+1;i<=n;i++)sum2+=a[i].a2;
			cout<<sum1+sum2<<endl;
		}
		if(n==2){
			int idx=1;
			ans[idx++]=a[1].a1+a[2].a2;
			ans[idx++]=a[1].a1+a[2].a3;
			ans[idx++]=a[1].a2+a[2].a1;
			ans[idx++]=a[1].a2+a[2].a3;
			ans[idx++]=a[1].a3+a[2].a1;
			ans[idx++]=a[1].a3+a[2].a2;
			for(int i=1;i<=5;i++){
				if(ans[i]>ans[i+1]){
					int t=ans[i];
					ans[i]=ans[i+1];
					ans[i+1]=t;
				}
			}
			cout<<ans[6]<<endl;
		}
	}
	return 0;
}
