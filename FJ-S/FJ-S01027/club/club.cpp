#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e6+5;

struct Node{
	int num;
	int idx;
}a[N][5];

bool cmp(Node x,Node y){
	return x.num>y.num;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].num;
				a[i][j].idx=j;
			}
			sort(a[i]+1,a[i]+4,cmp);
		}
		vector<int> A,B,C;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(a[i][j].idx==1) A.push_back(a[i][j].num);
				if(a[i][j].idx==2) B.push_back(a[i][j].num);
				if(a[i][j].idx==3) C.push_back(a[i][j].num);
			}
		}
		sort(A.begin(),A.end()); sort(B.begin(),B.end()); sort(C.begin(),C.end());
		int ans=0;
		for(int x=0;x<=n/2;x++){
			for(int y=0;y<=n/2;y++){
				int z=n-x-y, sum=0;
				if(z>n/2) continue;
//				cout<<x<<" "<<y<<" "<<z<<"\n";
				for(int i=0;i<=x;i++){
					sum+=A[i];
//					cout<<"A:"<<A[i]<<" ";
				}
//				cout<<"\n";
				for(int i=0;i<=y;i++){
					sum+=B[i];
//					cout<<"B:"<<B[i]<<" ";
				}
//				cout<<"\n";
				for(int i=0;i<=z;i++){
					sum+=C[i];
//					cout<<"C:"<<C[i]<<" ";
				}
//				cout<<"\n\n";
				ans=max(ans,sum);
            }
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1
2
10 9 8
4 0 0
*/
