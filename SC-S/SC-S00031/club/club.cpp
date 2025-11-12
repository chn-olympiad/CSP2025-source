#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t;
ll n;
struct stu{
	ll fi,se,th;
	ll ss1,ss2;
}a[100005];
ll ans;
bool cmp(stu x,stu y){
	return max(x.ss1,x.ss2)>max(y.ss1,y.ss2);
}
ll _1,_2,_3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i].fi>>a[i].se>>a[i].th;
			a[i].ss1=a[i].se-a[i].fi;
			a[i].ss2=a[i].th-a[i].fi;
			ans+=a[i].fi;
		}
		sort(a+1,a+1+n,cmp);
		_1=n;
		for(ll i=1;i<=n;i++){
			if((a[i].ss1>=a[i].ss2||_3==n/2)&&a[i].ss1>0&&_2<n/2){
				ans+=a[i].ss1;
				_1--;
				_2++;
			}
			if((a[i].ss2>=a[i].ss1||_2==n/2)&&a[i].ss2>0&&_3<n/2){
				ans+=a[i].ss2;
				_1--;
				_3++;
			}
		}	
		if(_1<=n/2)	cout<<ans<<endl;
		else{
			for(int i=1;i<=n;i++){
				if(a[i].ss1<=0&&(a[i].ss1>=a[i].ss2||_3==n/2)){
					ans+=a[i].ss1;
					_1--;
					_2++;
					if(_1<=n/2){
						break;
					}
				}
				if(a[i].ss2<=0&&(a[i].ss2>=a[i].ss1||_2==n/2)){
					ans+=a[i].ss1;
					_1--;
					_3++;
					if(_1<=n/2){
						break;
					}
				}
			}
			cout<<ans<<endl;
		}
		ans=0;
		_1=_2=_3=0;
		memset(a,0,sizeof(a));
	}
	return 0;
}