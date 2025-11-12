#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
long long a[N],b[N];
long long pre[25][N],dp[N],vis[N];
long long n,m,k,t,sum=0,ans=0,mx,mn;
struct al{
	long long x,y,sum=0;
}c[N];

string s,s1,s2;
void cal(int x){
	int cnt=0;
	while(x>0){
		cnt++;
		if(x%2==1){
			b[cnt]++;
		}x/=2;
		
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0); 
	cin>>n>>k;
	
	int p=k;
	vector<int>v(25);
	int cnt=0;
	while(k>0){
		cnt++;
		if(k%2==1){
			v[cnt]=1;
		}k/=2;
		
	}
	m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cal(a[i]);
		for(int j=1;j<=21;j++){
			pre[j][i]=pre[j][i-1]+b[j];
		}
		for(int j=0;j<=21;j++)b[j]=0;
		
		
//		if(a[i]==p){
////			cout<<"=-="<<i<<" "<<a[i]<<" "<<m<<endl;
//			ans++;
//			m=i;
//		}else {
			for(int j=m;j<i;j++){
		
				int ok=1;
				for(int jj=1;jj<=21;jj++){
					if((pre[jj][i]-pre[jj][j])%2!=v[jj]){
						ok=0;
						break;
					}
				}
				if(ok==1){
//					cout<<m<<" "<<j<<" "<<i<<endl;
					
					ans++;
					m=i;
					break;
//					for(int j=0;j<=25;j++)cout<<b[j]<<" ";
//					cout<<"-"<<i<<endl;
				
				}
			}
//		}
	}	
//	for(int jj=1;jj<=21;jj++){
//		for(int i=1;i<=n;i++)cout<<jj<<"-"<<pre[jj][i]<<" ";
//		cout<<endl;
//	}
	cout<<ans;
	return 0;
}
/*
4 2
2 1 0 3

2
--
4 3
2 1 0 3

2
--
4 0
2 1 0 3

1
*/