#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][4];
int b[4];
vector<int>c;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		c.clear();
		b[1]=b[2]=b[3]=0;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				b[1]++;
				ans+=a[i][1];
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				b[2]++;
				ans+=a[i][2];
			}
			else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
				b[3]++;
				ans+=a[i][3];
			}
		}
		if(max(b[1],max(b[2],b[3]))<=n/2){
			cout<<ans<<endl;
			continue;
		}
		if(b[1]>n/2)
		{
			for(int i=1;i<=n;i++){
				if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
					c.push_back(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
				}
			}
			sort(c.begin(),c.end(),cmp);
			for(int i=0;i<b[1]-n/2;i++){
				
				ans-=c[i];
			}
		}
		else if(b[2]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][2]>=a[i][3]&&a[i][2]>=a[i][1]){
					c.push_back(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
				}
			}
			sort(c.begin(),c.end(),cmp);
			for(int i=0;i<b[2]-n/2;i++){
				ans-=c[i];
			}
		}
		else if(b[3]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
					c.push_back(min(a[i][3]-a[i][1],a[i][3]-a[i][2]));
				}
			}
			sort(c.begin(),c.end(),cmp);
			for(int i=0;i<b[3]-n/2;i++){
				ans-=c[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
