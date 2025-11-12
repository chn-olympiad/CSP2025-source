#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][3],c[3],s;
vector<int>b;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin>>t;
	while(t--){
		s=0;
		b.clear();
		cin>>n;
		c[0]=c[1]=c[2]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				c[0]++;
				s+=a[i][0];
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				c[1]++;
				s+=a[i][1];
			}
			else{
				c[2]++;
				s+=a[i][2];
			}
		}
		if(c[0]<=n/2&&c[1]<=n/2&&c[2]<=n/2){
			cout<<s<<'\n';
		}
		else if(c[0]>=c[1]&&c[0]>=c[2]){
			for(int i=1;i<=n;i++){
				if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
					b.push_back(min(a[i][0]-a[i][1],a[i][0]-a[i][2]));
				}
			}
			sort(b.begin(),b.end());
			for(int i=1;i<=c[0]-n/2;i++){
				s-=b[i-1];
			}
			cout<<s<<'\n';
		}
		else if(c[1]>=c[0]&&c[1]>=c[2]){
			for(int i=1;i<=n;i++){
				if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
					b.push_back(min(a[i][1]-a[i][0],a[i][1]-a[i][2]));
				}
			}
			sort(b.begin(),b.end());
			for(int i=1;i<=c[1]-n/2;i++){
				s-=b[i-1];
			}
			cout<<s<<'\n';
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]){
					b.push_back(min(a[i][2]-a[i][0],a[i][2]-a[i][1]));
				}
			}
			sort(b.begin(),b.end());
			for(int i=1;i<=c[2]-n/2;i++){
				s-=b[i-1];
			}
			cout<<s<<'\n';
		}
	}
	return 0;
}
