#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node {
	double p;
	int i,num;
};
bool cmp(node x,node y) {
	if(x.p==y.p)return x.num>y.num;
	return x.p>y.p;
}
int a[N][5];
deque<node>b[5];
int d[N][5];
int T,n;
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		memset(a,0,sizeof a);
		memset(d,0,sizeof d);
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int x=a[i][1]+a[i][2]+a[i][3];
			b[1].push_back({a[i][1]*1.0/x,i,a[i][1]});
			b[2].push_back({a[i][2]*1.0/x,i,a[i][2]});
			b[3].push_back({a[i][3]*1.0/x,i,a[i][3]});
		}
		sort(b[1].begin(),b[1].end(),cmp);
		sort(b[2].begin(),b[2].end(),cmp);
		sort(b[3].begin(),b[3].end(),cmp);
		
		int now=n;
		int ans=0;
		for(int I=1; I<=3; I++)

			 
				for(int i=0; i<n; i++) {
					d[b[I][i].i-1][I]=i+1;
		}
//		 for(int i=0; i<n; i++){
//			 for(int I=1; I<=3; I++){
//				cout<<d[i][I]<<" ";
//			}
//			cout<<endl;
//		}	
		
		int mx[4];
		mx[1]=mx[2]=mx[3]=0;
		for(int I=1; I<=3; I++){
			 for(int p=1;p<=n/2;p++){
			 	
			 		mx[I]+=b[I][p-1].num;
			
				
			}
		}	
		cout<<max({mx[1],mx[2],mx[3]})<<endl;
		
//		cout<<ans<<endl;	
//		for(int I=1; I<=3; I++)
//		for(int p=1; p<=n/2&&p<=now; p++) {
//			for(int i=0; i<n; i++) {
//				ans+=b[I][i].num;
//				now--;
//				b[I].pop_front();
//			}
//		}
//		cout<<ans<<endl;

	}
}