#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
long long c;
map<vector<int>,int> mp[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>=2*a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(a[n]==1){
		long long s=0;
		for(int i=3;i<=n;i++){
			long long x=1;
			for(int j=1;j<=i;j++){
				x*=n-j+1;
			}
			for(int j=2;j<=i;j++){
				x/=j;
			}
			s+=x;
			s%=998244353;
		}
		cout<<s;
	}else if(a[n]<=100){
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				mp[2][{j,i}]=a[j]+a[i];
			}
		}
//		for(auto p:mp[2]){
//			for(int i=0;i<2;i++){
//				cout<<p.first[i]<<' ';
//			}
//			cout<<p.second<<"\n";
//		}
		long long s=0;
		for(int i=3;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(auto p:mp[i-1]){
//					cout<<i<<'\n';
					vector<int> x=p.first;
					if(p.first[i-2]>=j){
//						cout<<"1\n";
						continue;
					}else{
						c++;
						x.push_back(j);

						if(p.second>a[j]){
							s++;
//							for(int er=0;er<x.size();er++){
//								cout<<x[er]<<" ";
//							}
//							cout<<endl;						
						}						
						mp[i][x]=p.second+a[j];
						x.erase(x.begin()+i);
					}
				}
				s%=998244353;
			}
		}
		cout<<s<<'\n';
//		cout<<c;
	}
	return 0;
}

