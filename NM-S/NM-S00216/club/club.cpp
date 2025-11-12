#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int t,n[N],mi=9999,ma,ans[N];
int a[N][5],s;
int main(){
	freopen("club.in","r",stdin);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			ans[i]+=a[j][1];
			ma=max(ma,a[j][1]);
		}
		for(int k=1,q=1;k<=n[i]&&q<=n[i]/2;k++){
			if(mi>a[k][1]){
				q++;
				s=k;
			}
			mi=min(mi,a[k][1]);
			if(k==n[i]&&q!=n[i]/2){
				k=1;
				ans[i]-=mi;
				a[s][1]==9999;
			}
		}
		ans[i]-=mi;
	}
	for(int i=1;i<=t;i++){
		cout<<ans[t];
	}
	freopen("club.out","w",stdout);
	return 0;
}
