#include<bits/stdc++.h>
using namespace std;
int T;
struct club{
	int a1,a2,a3;
	int f=0;
}a[100005];
bool gz1(club x,club y){
	return x.a1>y.a1;
}
bool gz2(club x,club y){
	return x.a2>y.a2;
}
long long int ans=0;
int main(){
	freopen("club.in","r",stdin)
	freopen("club.out","w",stdout)
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int nn=n;
		int nnn=n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		n/=2;
		int j=0;
		sort(a+1,a+1+nnn,gz1);
		for(int i=1;i<=nnn;i++){
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){
				ans+=a[i].a1;
				a[i].f=1;
				nn--;
				j++;
			}
		}
		if(j>n){
			for(int i=nnn;i>=1;i--){
				if(a[i].f==1){
					a[i].f=0;
					ans-=a[i].a1;
					j--;
				}
				if(j<=n){
					break;
				}
			}
		}
		j=0;
		sort(a+1,a+1+nnn,gz2);
		for(int i=1;i<=nnn;i++){
			if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3&&a[i].f==0){
				ans+=a[i].a2;
				a[i].f=2;
				nn--;
				j++;
			}
		}
		if(j>n){
			for(int i=nnn;i>=1;i--){
				if(a[i].f==2){
					a[i].f=0;
					ans-=a[i].a2;
					j--;
				}
				if(j<=n){
					break;
				}
			}
		}
		for(int i=1;i<=nnn;i++){
			if(a[i].f==0){
				ans+=a[i].a3;
			}
		}
		cout<<ans;
	}
	return 0;
}
