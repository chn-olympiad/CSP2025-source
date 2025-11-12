#include<bits/stdc++.h>
using namespace std;
int t;
long long n,m[100005][5],ans,tot1,tot2,tot3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int a=1;a<=t;a++) {
		ans=0;tot1=0;tot2=0;tot3=0;
		cin>>n;
		for(int b=1;b<=n;b++) cin>>m[b][1]>>m[b][2]>>m[b][3];
		for(int i=n;i>=1;i--) {
			if(max(m[i][1],max(m[i][2],m[i][3]))==m[i][1]) {
				if(tot1<n/2){
					tot1++;
					ans+=m[i][1];
//					break;
				}else {
					if(m[i][2]>=m[i][3]) {
//						if(tot2<n/2) {
							tot2++;
							ans+=m[i][2];
//							break;
//						}
					}else  {
//						if(tot3<=n/2) {
							tot3++;
							ans+=m[i][3];
//							break;
//						}
					}
				}
			}else if(max(m[i][1],max(m[i][2],m[i][3]))==m[i][2]) {
				if(tot2<n/2){
					tot2++;
					ans+=m[i][2];
//					break;
				}else {
					if(m[i][1]>=m[i][3]) {
//						if(tot1<n/2) {
							tot1++;
							ans+=m[i][1];
//							break;
//						}
					}else  {
//						if(tot3<n/2) {
							tot3++;
							ans+=m[i][3];
//							break;
//						}
					}
				}
			}else if(max(m[i][1],max(m[i][2],m[i][3]))==m[i][3]) {
				if(tot3<n/2){
					tot3++;
					ans+=m[i][3];
//					break;
				}else {
					if(m[i][2]>=m[i][1]) {
//						if(tot2<n/2) {
							tot2++;
							ans+=m[i][2];
//							break;
//						}
					}else  {
//						if(tot1<n/2) {
							tot1++;
							ans+=m[i][1];
//							break;
//						}
					}
				}
			}
//			cout<<ans<<' ';
		}
		cout<<ans<<'\n';
	}
	return 0;
}
