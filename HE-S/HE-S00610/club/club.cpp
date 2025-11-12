#include<bits/stdc++.h>
using namespace std;
int t;
long long n[7],m[7][3];
struct st{
	long long a;
	long long b;
	long long c;
}k[7][100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			cin>>k[i][j].a>>k[i][j].b>>k[i][j].c;
		}
		for(int j=1;j<=n[i];j++){
			for(int l=1;l<=n[i];l++){
				if(k[i][l].a<k[i][l+1].a)swap(k[i][l],k[i][l+1]);
			}
		}
		for(int j=1;j<=n[i]/2;j++){
			m[i][1]+=k[i][j].a;
		}
		for(int j=n[i]/2+1;j<=n[i];j++){
			m[i][1]+=max(k[i][j].b,k[i][j].c);
		}
		for(int j=1;j<=n[i];j++){
			for(int l=1;l<=n[i];l++){
				if(k[i][l].b<k[i][l+1].b)swap(k[i][l],k[i][l+1]);
			}
		}
		for(int j=1;j<=n[i]/2;j++){
			m[i][2]+=k[i][j].b;
		}
		for(int j=n[i]/2+1;j<=n[i];j++){
			m[i][2]+=max(k[i][j].a,k[i][j].c);
		}
		for(int j=1;j<=n[i];j++){
			for(int l=1;l<=n[i];l++){
				if(k[i][l].c<k[i][l+1].c)swap(k[i][l],k[i][l+1]);
			}
		}
		for(int j=1;j<=n[i]/2;j++){
			m[i][3]+=k[i][j].c;
		}
		for(int j=n[i]/2+1;j<=n[i];j++){
			m[i][3]+=max(k[i][j].a,k[i][j].b);
		}
		cout<<max(m[i][1],max(m[i][2],m[i][3]))<<endl;
	}
	return 0;
} 
