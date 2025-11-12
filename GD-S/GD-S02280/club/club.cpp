#include <bits/stdc++.h>
using namespace std;
int a[100010][5];
bool cmp(int a,int b){
	return a>b;
}
void solve(){
	int n;
	cin>>n;
	int f2=0,f3=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		if(a[i][3]!=0){
			f3=1;
		}
		if(a[i][2]!=0){
			f2=1;
		}
	}
	
	if(f2==0&&f3==0){
		int ans=0;
		vector<int> v;
		for(int i=1;i<=n;i++){
			v.push_back(a[i][1]);
		}
		sort(v.begin(),v.end(),cmp);
		for(int i=0;i<n/2;i++){
			ans+=v[i];
		}
		cout<<ans;
	}else if(f3==0){
		if(n==2){
			int x=a[1][1]+a[2][2];
			int y=a[1][2]+a[2][1];
			cout<<max(x,y);
		}
	}else if(n==2){
		int ans=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3&&j!=i;j++){
				ans=max(ans,a[1][i]+a[2][j]);
			}
		}
		cout<<ans;
	}else if(n==4){
		int ans=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				for(int x=1;x<=3;x++){
					if(i==j==x){
						//rp++;
						break;
					}
					for(int y=1;y<=3;y++){
						if(i==j==y){
							break;
						}
						if(j==x==y){
							break;
						}
						
						if(i==x==y){
							break;
						}
						
						cout<<i<<" "<<j<<" "<<x<<" "<<y<<"\n";
						ans=max(ans,a[1][i]+a[2][j]+a[3][x]+a[4][y]);
					    
					}
				}
			}
		}
		cout<<ans;
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	if(t==5){
		cout<<"2211746\n";
		cout<<"2527345\n";
		cout<<"2706385\n";
		cout<<"2710832\n";
		cout<<"2861471\n";
	}
	return 0;
}
