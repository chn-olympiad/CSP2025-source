#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
using ll=long long;
const int Cnt=1e5+4;
int t,n;
struct f{
	int id,zhi;
}A[Cnt][5];
bool cmp(const f a,const f b){
	return a.zhi>b.zhi;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		vector<vector<int> > B(4);
		vector<int> C;
		ll sum=0;
		REP(z,1,n){
			REP(i,1,3)cin>>A[z][i].zhi,A[z][i].id=i;
			sort(A[z]+1,A[z]+4,cmp);
			B[A[z][1].id].push_back(z);
			sum+=A[z][1].zhi;
		}
		REP(z,1,3){
			if(B[z].size()>n/2){
				for(int i:B[z]){
					C.push_back(A[i][1].zhi-A[i][2].zhi);
				}
				sort(C.begin(),C.end());
				for(int i=0;i<B[z].size()-n/2;i++)sum-=C[i];
				break;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}