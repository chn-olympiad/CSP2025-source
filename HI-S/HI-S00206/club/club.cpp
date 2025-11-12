#include<bits/stdc++.h>
using namespace std;
long long n,m;
int t;
bool f=1;
vector<long long> v1[4];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++){
		cin>>n;
		m=n/2;
		long long a,dp[100500],p1=0,p=0,c=0,p2=0,p3=0;
		dp[1]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a;
				p1=max(p1,a);
				v1[j].push_back(a);
			}
			p+=p1;
			p2++;
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(v1[1][i]<v1[1][j]){
					swap(v1[1][j],v1[1][i]);
					swap(v1[2][j],v1[2][i]);
					swap(v1[3][j],v1[3][i]);
				}
				else if(v1[2][i]<v1[2][j]){
					swap(v1[1][j],v1[1][i]);
					swap(v1[2][j],v1[2][i]);
					swap(v1[3][j],v1[3][i]);	
				}
			}
		}
		for(int i=0;i<m;i++){
			if(v1[1][i]!=0){
				p3++;
				c+=v1[1][i];
				v1[1].erase(v1[1].begin()+i);
			}
		}
		for(int i=0;i<m;i++){
			if(v1[2][i]!=0){
				p3++;
				c+=v1[2][i];
				v1[2].erase(v1[2].begin()+i);
			}
		}
		for(int i=0;i<m;i++){
			if(v1[3][i]!=0){
				p3++;
				c+=v1[3][i];
				v1[3].erase(v1[3].begin()+i);
			}
		}
		if(p3<p2){
			cout<<min(c,p)<<"\n";
		}
		else{
			cout<<max(c,p)<<"\n";
		}
		v1[1].clear();
		v1[2].clear();
		v1[3].clear();
	}	

	return 0;
} 
