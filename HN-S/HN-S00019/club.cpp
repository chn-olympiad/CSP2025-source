#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int a[N][5],n,T;
vector<int> c[5]; 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		for (int i=1;i<=3;i++)	c[i].clear();
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		int c1=0,c2=0,c3=0;
		int sum=0;
		for (int i=1;i<=n;i++){
			int a1=a[i][1],a2=a[i][2],a3=a[i][3];
			sum+=max(a1,max(a2,a3));
			if (a1>=a2&&a2>=a3){
				c1++;
				c[1].push_back(a2-a1);
			}if (a1>=a3&&a3>a2){
				c1++;
				c[1].push_back(a3-a1);
			}
			if (a3>=a2&&a2>a1){
				c3++;
				c[3].push_back(a2-a3);
			}if (a2>=a3&&a3>a1){
				c2++;
				c[2].push_back(a3-a2);
			}
			if (a3>=a1&&a1>=a2){
				c3++;
				c[3].push_back(a1-a3);
			}if (a2>=a1&&a1>=a3){
				c2++;
				c[2].push_back(a1-a2);
			}
		}
		if (c1>n/2){
			sort(c[1].begin(),c[1].end());
			int k=0; 
			for (int i=c[1].size()-1;i>=0;i--){
				k++;
				sum+=c[1][i];
				if (c1-k<=n/2)		break;
			}
		}if (c2>n/2){
			sort(c[2].begin(),c[2].end());
			int k=0; 
			for (int i=c[2].size()-1;i>=0;i--){
				k++;
				sum+=c[2][i];
				if (c2-k<=n/2)		break;			
			}
		}if (c3>n/2){
			sort(c[3].begin(),c[3].end());
			int k=0; 
			for (int i=c[3].size()-1;i>=0;i--){
				k++;
				sum+=c[3][i];
				if (c3-k<=n/2)		break;
			}
		}
		cout<<sum<<"\n";
		
	}
	return 0;
}

