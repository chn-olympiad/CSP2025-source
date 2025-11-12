#include<bits/stdc++.h>
using namespace std;
int n,t;
struct stu{int a1,a2,a3,mx,mk;}a[200005];
long long ans;
bool cmp(stu x,stu y){
	return x.mx>y.mx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1>a[i].a2){
				if(a[i].a1>a[i].a3) a[i].mx=a[i].a1,a[i].mk=1;
				else a[i].mx=a[i].a3,a[i].mk=3;
			}
			else{
				if(a[i].a2>a[i].a3) a[i].mx=a[i].a2,a[i].mk=2;
				else a[i].mx=a[i].a3,a[i].mk=3;
			}
		}
		int cnt1,cnt2,cnt3;
		cnt1=n/2,cnt2=cnt1,cnt3=cnt2;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].mk==1){
				if(cnt1>0){ans+=a[i].mx,cnt1--;}
				
				else if(a[i].a2>a[i].a3){
					if(cnt2>0){ans+=a[i].a2,cnt2--;}
					else ans+=a[i].a3,cnt3--;
				}
				else{
					if(cnt3>0){ans+=a[i].a3,cnt3--;}
					else ans+=a[i].a2,cnt2--;
				}
			}
			if(a[i].mk==2){
				if(cnt2>0){ans+=a[i].mx,cnt2--;}
				else if(a[i].a1>a[i].a3){
					if(cnt1>0){ans+=a[i].a1,cnt1--;}
					else ans+=a[i].a3,cnt3--;
				}
				else{
					if(cnt3>0){ans+=a[i].a3,cnt3--;}
					else ans+=a[i].a1,cnt1--;
				}
			}
			if(a[i].mk==3){
				if(cnt3>0){ans+=a[i].mx,cnt3--;}
				else if(a[i].a1>a[i].a2){
					if(cnt2>0){ans+=a[i].a1,cnt1--;}
					else ans+=a[i].a2,cnt2--;
				}
				else{
					if(cnt2>0){ans+=a[i].a2,cnt2--;}
					else ans+=a[i].a1,cnt1--;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
