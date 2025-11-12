#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,ans,a,b,c;
vector<int> A;
vector<int> B;
vector<int> C;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("club4.in","r",stdin);
	freopen("club4.out","w",stdout);
	cin>>T;
	while(T--){
		A.clear(),B.clear(),C.clear(); 
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>=b&&a>=c)
				A.push_back(a-max(b,c)),ans+=a;
			else if(b>=a&&b>=c)
				B.push_back(b-max(a,c)),ans+=b;
			else 
				C.push_back(c-max(a,b)),ans+=c;
		} 
		if(A.size()>n/2){
			int t=A.size()-n/2,cnt=0;
			sort(A.begin(),A.end());
			while(t--){	
				//cout<<A[cnt]<<' ';
				ans-=A[cnt++];
			
			}
			//cout<<"A ";
		}
		if(B.size()>n/2){
			int t=B.size()-n/2,cnt=0;
			sort(B.begin(),B.end());
			while(t--){
				ans-=B[cnt++];
			}
		}
		if(C.size()>n/2){
			int t=C.size()-n/2,cnt=0;
			sort(C.begin(),C.end());
			while(t--){
				ans-=C[cnt++];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
