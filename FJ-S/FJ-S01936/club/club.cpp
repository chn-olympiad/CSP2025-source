#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int a,b,c,q[n+10],p[5],k=0;
		memset(p,0,sizeof(p));
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			q[k]=max(a,max(b,c));
			k++;
		}
		for(int i=0;i<k;i++) p[q[i]]++;
		int x=(p[0]+p[1]+p[2])/2,f=1;
		for(int i=0;i<n;i++) 
			if(p[i]>x) f=0;
		int ans=0;
		if(f==1)
			for(int i=0;i<n;i++) ans+=q[i];
		cout<<ans<<"\n";
	}
	return 0;
} 
