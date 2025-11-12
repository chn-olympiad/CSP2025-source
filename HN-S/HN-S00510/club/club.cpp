#include<bits/stdc++.h>
using namespace std;
long long T,n,qwe,asd,zxc,ans,cnt[4];
void slove(){
	priority_queue<long long,vector<long long>,greater<long long> > q[4];
	cnt[1]=0,cnt[2]=0,cnt[3]=0;
	ans=0;
	//
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>qwe>>asd>>zxc;
		long long mmax=max(qwe,max(asd,zxc));
		if(mmax==qwe){
			if(cnt[1]>=n/2){
				if(max(asd,zxc)>=qwe-q[1].top()){
					ans+=max(asd,zxc);
				}else{
					ans+=qwe-q[1].top();
					q[1].pop(),q[1].push(qwe-max(asd,zxc));
				}
			}else{
				q[1].push(qwe-max(asd,zxc)),ans+=mmax,cnt[1]++;
			}
		}else{
			if(mmax==asd){
				if(cnt[2]>=n/2){
					if(max(qwe,zxc)>=asd-q[2].top()){
						ans+=max(qwe,zxc);
					}else{
						ans+=asd-q[2].top();
						q[2].pop(),q[2].push(asd-max(qwe,zxc));
					}
				}else{
					q[2].push(asd-max(qwe,zxc)),ans+=mmax,cnt[2]++;
				}
			}else{
				if(cnt[3]>=n/2){
					if(max(qwe,asd)>=zxc-q[3].top()){
						ans+=max(qwe,asd);
					}else{
						ans+=zxc-q[3].top();
						q[3].pop(),q[3].push(zxc-max(asd,qwe));
					}
				}else{
					q[3].push(zxc-max(asd,qwe)),ans+=mmax,cnt[3]++;
				}
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	//冷静下来  我相信你 
	//ios别炸 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		slove();
	}
	return 0;
}
