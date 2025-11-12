#include<bits/stdc++.h>

using namespace std;

int ct[3];
int r[3][20005];

inline void c(){
	memset(ct,0,sizeof(ct));
		memset(r,0,sizeof(r));
		int ans=0;
		
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int a[3];
			scanf("%d %d %d",&a[0],&a[1],&a[2]);
			int b[2];
			bool c01=a[0]>a[1],c02=a[0]>a[2],c12=a[1]>a[2];
			#define c10 !c01
			#define c20 !c02
			#define c21 !c12
			if(c20&&c01){
				b[0]=2;
				b[1]=0;
			}
			if(c21&&c10){
				b[0]=2;
				b[1]=1;
			}
			if(c10&&c02){
				b[0]=1;
				b[1]=0;
			}
			if(c12&&c20){
				b[0]=1;
				b[1]=2;
			}
			if(c01&&c12){
				b[0]=0;
				b[1]=1;
			}
			if(c02&&c21){
				b[0]=0;
				b[1]=2;
			}
			ct[b[0]]++;
			ans+=a[b[0]];
			r[b[0]][a[b[0]]-a[b[1]]]++;
			//cout<<a[b[0]]-a[b[0]]<<endl;
		}
		int v=-1;
		if(ct[0]>n/2)v=0;
		if(ct[1]>n/2)v=1;
		if(ct[2]>n/2)v=2;
		if(v!=-1)
			for(int i=0;i<=20000;i++){
				ans-=min(r[v][i],ct[v]-n/2)*i;
				ct[v]-=min(r[v][i],ct[v]-n/2);
				if(ct[v]<=n/2)break;
			}
		cout<<ans<<endl;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	
	while(t--){
		c();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

