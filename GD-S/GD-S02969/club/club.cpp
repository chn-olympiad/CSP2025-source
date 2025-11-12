#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int A[N][4],n;
vector<int> B[4];
void solve() {
	cin>>n;
	int ans=0;
	B[1].clear();B[2].clear();B[3].clear();
	for(int i=1;i<=n;i++) {
		int mxi=0,mx2=0;
		A[i][0]=-1;
		for(int j=1;j<=3;j++) {
			cin>>A[i][j];
			if(A[i][j]>A[i][mxi]) mx2=mxi,mxi=j;
			else if(A[i][j]>A[i][mx2]) mx2=j;
		}
//		cout<<mxi<<" "<<mx2<<endl;
		B[mxi].push_back(A[i][mxi]-A[i][mx2]);
		ans+=A[i][mxi];
	}
	if((int)max(B[1].size(),max(B[2].size(),B[3].size()))<=n/2)
		cout<<ans<<endl;
	else {
		vector<int> C;
		if((int)B[1].size()>n/2) C=B[1];
		else if((int)B[2].size()>n/2) C=B[2];
		else C=B[3];
		sort(C.begin(),C.end());
//		cout<<"fxxk "<<C.size()<<"\n";
		for(int i=0;i<(int)C.size()-n/2;i++) {
			ans-=C[i];
//			cout<<" "<<C[i]<<endl;
		}
		cout<<ans<<endl;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin>>t;
	while(t--) solve(); 
}
