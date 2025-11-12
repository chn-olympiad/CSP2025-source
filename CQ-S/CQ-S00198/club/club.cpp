#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;

const int N=1e5+5;
int n,sum[3];
struct nnd {
	int w,id;
}A[N][3];
struct mmb {
	int x,a,b;
}B[N];
bool pai1(nnd x,nnd y){
	return x.w > y.w ;
}
bool pai2(mmb x,mmb y){
	return x.a > y.a ;
}
priority_queue<int>q[3];
void work(){
	cin>>n;
	for(int i=0;i<3;i++){
		sum[i]=0;
		while(q[i].size())
			q[i].pop();
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			cin>>A[i][j].w;
			A[i][j].id=j;
		}
		sort(A[i],A[i]+3,pai1);
		B[i]=(mmb){A[i][0].id,A[i][0].w,A[i][1].w};
//		cout<<B[i].x<<" "<<B[i].a<<" "<<B[i].b<<"\n";
	}
	sort(B+1,B+n+1,pai2);
	ll ans=0;
//	cerr<<n<<" "<<"man!\n";
	for(int i=1;i<=n;i++){
		int x=B[i].x,a=B[i].a,b=B[i].b; 
//		cerr<<"	"<<x<<" "<<a<<" "<<b<<"\n";
		if(q[x].size()>=n/2){
			if(a+q[x].top()>b){
				ans+=a+q[x].top();
//				cerr<<"		"<<a+q[x].top()<<"\n";
				q[x].pop();
				q[x].push(b-a);
			} else {
				ans+=b;
//				cerr<<"		"<<b<<"\n";
			}
		} else {
			ans+=a;
//			cerr<<"		"<<a<<"\n";
			q[x].push(b-a);
		}
	}
	cout<<ans<<"\n";
//	cerr<<ans<<"\n";
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	while(t--)
		work();
	
	return 0;
}
