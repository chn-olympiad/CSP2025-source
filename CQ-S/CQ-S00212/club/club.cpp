#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct zky{
	int f,s,t;
	int mx,num;
}a[N];
void f2(){
	cout<<max(a[1].f+a[2].s,max(a[1].f+a[2].t,max(a[1].s+a[2].f,max(a[1].s+a[2].t,
	max(a[1].t+a[2].f,a[1].t+a[2].s)))))<<"\n";
}
bool cmp(zky a,zky b){
	if(a.mx!=b.mx)return a.mx>b.mx;
}
int main(){
	freopen("club.in","r",stdin);
  	freopen("club.out","w",stdout);
	//ios::sync_with_stdio(false);
//	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,flag=0,cnt1=0,cnt2=0,cnt3=0;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
			a[i].mx=max({a[i].f,a[i].s,a[i].t});
		//	cout<<a[i].mx<<" ";
			a[i].num=a[i].f+a[i].s+a[i].t;
			if(a[i].s==0&&a[i].t==0)flag=1;
			else if(a[i].t==0)flag=2;
		}	
		sort(a+1,a+n+1,cmp);
		if(n==2){f2();continue; }
		if(flag==1){
			for(int i=1;i<=n/2;i++){
				//cout<<a[i].f<<" "<<a[i].s<<" "<<a[i].t<<"\n";
				ans+=a[i].mx;
			}
			cout<<ans<<"\n";
		}
	
		if(flag==2){
			for(int i=1;i<=n;i++){
				if(a[i].mx==a[i].f){
				if(cnt1<n/2){
				cnt1++;
				ans+=a[i].mx;
				}else{
					ans+=a[i].s;
					cnt2++;
				}			
			}
			else if(a[i].mx==a[i].s){
				if(cnt2<n/2){
					cnt2++;
					ans+=a[i].mx;
				}
				else{
					ans+=a[i].f;
					cnt1++;
				}
			}	
					
			}
			cout<<ans<<"\n";
		}
		if(flag==0){
			for(int i=1;i<=n;i++){
				//cout<<a[i].f<<" "<<a[i].s<<" "<<a[i].t<<"\n";
				if(a[i].mx==a[i].f){
					if(cnt1<n/2){
						cnt1++;
						ans+=a[i].mx;
					}else{ //cnt>n/2
						long long smx=max(a[i].s,a[i].t);
						if(smx==a[i].s){
						//	if(cnt2<=n/2){
								ans+=a[i].s;
								cnt2++;
						//	}
						}else if(smx==a[i].t){
							ans+=a[i].t;
							cnt3++;	
						}
					}
				}else if(a[i].mx==a[i].s){
					if(cnt2<n/2){
						cnt2++;
						ans+=a[i].mx;
					}else{//cnt2>n/2
						long long smx=max(a[i].f,a[i].t);
						if(smx==a[i].f){
							ans+=a[i].f;
							cnt1++;
						}else if(smx==a[i].t){
							ans+=a[i].t;
							cnt3++;
						}	
					}
				}else if(a[i].mx==a[i].t){
					if(cnt3<n/2){
						cnt3++;
						ans+=a[i].mx;
					}else{//cnt3>n/2
						long long smx=max(a[i].f,a[i].s);
						if(smx==a[i].f){
							cnt1++;
							ans+=a[i].f;
						}else if(smx==a[i].s){
							cnt2++;
							ans+=a[i].s;
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
