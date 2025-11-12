#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int cnt1,cnt2,cnt3,sum1,sum2,sum3;
struct person{
	int m1,m2,m3,mx;
}a[N];
bool cmp(person x,person y){
	if(x.mx==y.mx){
		if(x.m1==y.m1){
			if(x.m2==y.m2)return x.m3>y.m3;
			return x.m2>y.m2;
		}
		return x.m1>y.m1;
	}
	return x.mx>y.mx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].m1>>a[i].m2>>a[i].m3;
			a[i].mx=max(max(a[i].m1,a[i].m2),a[i].m3);
		}
		sort(a+1,a+1+n,cmp);
		cnt1=cnt2=cnt3=sum1=sum2=sum3=0;
		if(n==2){
			int ans=a[1].m1+a[2].m2;
			ans=max(ans,a[1].m1+a[2].m3);
			ans=max(ans,a[1].m2+a[2].m1);
			ans=max(ans,a[1].m2+a[2].m3);
			ans=max(ans,a[1].m3+a[2].m1);
			ans=max(ans,a[1].m3+a[2].m2);
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i].mx==a[i].m1){
				if(cnt1!=n/2){
					cnt1++;
					sum1+=a[i].m1;
				}else{
					if(a[i].m2>a[i].m3){
						cnt2++;
						sum2+=a[i].m2;
					}else{
						cnt3++;
						sum3+=a[i].m3;
					}
				}
			}else if(a[i].mx==a[i].m2){
				if(cnt2!=n/2){
					cnt2++;
					sum2+=a[i].m2;
				}else{
					if(a[i].m1>a[i].m3){
						cnt1++;
						sum1+=a[i].m1;
					}else{
						cnt3++;
						sum3+=a[i].m3;
					}
				}
			}else if(a[i].mx==a[i].m3){
				if(cnt3!=n/2){
					cnt3++;
					sum3+=a[i].m3;
				}else{
					if(a[i].m1>a[i].m2){
						cnt1++;
						sum1+=a[i].m1;
					}else{
						cnt2++;
						sum2+=a[i].m2;
					}
				}
			}
		}
		cout<<sum1+sum2+sum3<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
