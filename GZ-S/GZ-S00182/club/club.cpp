//GZ-S00182 贵阳市云岩区中天中学 张颜淏
 #include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,cnt,ans=0,cnt1,cnt2,cnt3;
struct ai{
	int a1,a2,a3;
	int f,s,t;
	bool u=0;
}a[N];
bool cmp1(ai a,ai b){
	return a.a1>b.a1;
}
bool cmp2(ai a,ai b){
	return a.a2>b.a2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
		}
		if(n>=1e4&&n<=1e6){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a1;
			}
			cout<<ans<<endl;
			continue;
		}
		sort(a+1,a+1+n,cmp1);
		cnt=0;
		for(int i=1;i<=n&&cnt<=n/2;i++){
			if(!a[i].u){
				ans+=a[i].a1;
				a[i].u=1;
				cnt++;
			}
		}
		sort(a+1,a+1+n,cmp2);
		cnt=0;
		for(int i=1;i<=n/2&&cnt<=n/2;i++){
			if(!a[i].u){
				ans+=a[i].a2;
				a[i].u=1;
				cnt++;
			}
		}
	}
	cout<<ans;
	return 0;
}
