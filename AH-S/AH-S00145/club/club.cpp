#include <bits/stdc++.h>
using namespace std;

long long a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)  cin>>a[i]>>b[i]>>c[i];
		priority_queue<long long>q1,q2,q3;
		int sz1=0,sz2=0,sz3=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			int op=0;
			long long rp=max(a[i],max(b[i],c[i]));
			if (rp==a[i]) op=1;
			if (rp==b[i]) op=2;
			if (rp==c[i]) op=3;
			if (op==1){
				long long sp=max(b[i],c[i]);
				if (sz1<n/2){
					q1.push(sp-a[i]);
					sz1++;
					ans+=a[i];
				}
				else{
					if (sp-a[i]<q1.top()) ans+=q1.top(),ans+=a[i],q1.pop(),q1.push(sp-a[i]);
					else{
						ans+=sp;
					} 
				}
			}
			if (op==2){
				long long sp=max(a[i],c[i]);
				if (sz2<n/2){
					q2.push(sp-b[i]);
					sz2++;
					ans+=b[i];
				}
				else{
					if (sp-b[i]<q2.top()) ans+=q2.top(),q2.pop(),ans+=b[i],q2.push(sp-b[i]);
					else{
						ans+=sp;
					} 
				}
			}
			if (op==3){
				long long sp=max(b[i],a[i]);
				if (sz3<n/2){
					q3.push(sp-c[i]);
					sz3++;
					ans+=c[i];
				}
				else{
					if (sp-c[i]<q3.top()) ans+=q3.top(),q3.pop(),ans+=c[i],q3.push(sp-c[i]);
					else{
						ans+=sp;
					} 
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
