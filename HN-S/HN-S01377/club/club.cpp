#include<bits/stdc++.h>

using namespace std;
using ll=long long;

const int kMaxN=1e5+100;

int t,n,a[kMaxN][5],h,A[kMaxN],c,Z[kMaxN],s;
vector<int>z[5];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	for(cin>>t;t--;){
		cin>>n,s=0,z[0].clear(),z[1].clear(),z[2].clear();
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2],h=A[i]=0;
			for(int j=1;j<3;j++){
				a[i][j]>a[i][h]&&(h=j);
			}
			z[h].push_back(i),s+=a[i][h];
			for(int j=0;j<3;j++){
				j!=h&&(A[i]=max(A[i],a[i][j]));
			}
		}
		for(int i=0;i<3;i++){
			if(int(z[i].size())>n/2){
				c=0;
				for(int j:z[i]){
					Z[++c]=a[j][i]-A[j];
				}
				sort(Z+1,Z+c+1);
				for(int j=1;j<=int(z[i].size())-n/2;j++){
					s-=Z[j];
				}
			}
		}
		cout<<s<<'\n';
	}
	return 0;
}
