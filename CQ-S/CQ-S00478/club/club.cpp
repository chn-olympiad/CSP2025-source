#include<bits/stdc++.h>
using namespace std;
int t,n,s[5];
long long ans; 
int a[100005][5];
int ma[100005];
priority_queue<int,vector<int>,greater<int> > q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n; ans=0;
		while(!q.empty()) q.pop();
		s[1]=0; s[2]=0; s[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]<a[i][2]){
				if(a[i][2]<a[i][3]) ma[i]=3;
				else ma[i]=2;
			}else{
				if(a[i][1]<a[i][3]) ma[i]=3;
				else ma[i]=1;
			}
			s[ma[i]]++; ans+=a[i][ma[i]];
		}
		for(int i=1;i<=n;i++){
			if(s[i]>n/2){
				for(int j=1;j<=n;j++){
					if(ma[j]!=i) continue;
					int mi=100000;
					for(int k=1;k<=3;k++)
						if(k!=i) mi=min(mi,a[j][i]-a[j][k]);
					q.push(mi);
				}
				while(s[i]>n/2){
					ans-=q.top();
					q.pop(); s[i]--;
				}
				break;
			}
		}cout<<ans<<'\n';
	}
	return 0;
}
