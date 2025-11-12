#include <bits/stdc++.h>
using namespace std;

int a[100007][3],b[3];
vector<int> c[3];
int t,n;
void subt(){
	cin>>n;
	long long ans=0;
	b[0]=b[1]=b[2]=0;
	for(int j=0;j<3;j++) c[j].clear();
	for(int i=1;i<=n;i++){
		int mx=0,se=0,p=0;
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			if(mx<=a[i][j]) p=j,se=mx,mx=a[i][j];
			else if(se<a[i][j]) se=a[i][j];
		}
		b[p]++;
		c[p].push_back(mx-se);
		ans+=mx;
	}
	for(int i=0;i<3;i++){
		if(b[i]>n/2){
			b[i]-=n/2;
			sort(c[i].begin(),c[i].end());
			for(int j=0;j<b[i];j++) ans-=c[i][j];
			break;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in" ,"r",stdin );
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>t;
	while(t--) subt();
	return 0;
}
