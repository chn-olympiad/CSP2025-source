#include<iostream>
#include<vector>
#include<algorithm> 
#include<map>
#define MOD 998244353
using namespace std;
struct Node{
	vector<int> v;
	vector<int> cnt;
	int sum;
};
int n;
vector<int> a(5005,0),cnt(5005,0);
vector<vector<Node>> f(5005,vector<Node>());
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[i]++;
	}
	for(int i:a){
		if(i!=b.back()){
			b.push_back(i);
			f[1].push_back({i},{1},i);
		}
	}
	for(int i=2;i<=n;i++){
		for(Node num:f[i-1]){
			for(int j=1;j<=n;j++){
				bool flag1=true,flag2=false;
				for(int k=0;k<num.v.size();k++){
					if(a[j]==num.v[k]){
						if(num.cnt[k]+1>cnt[a[j]]){
							flag=false;
							break;
						}
						else{
							flag2=true;
							break;
						}
					}
				}
				if(flag1){
					if(flag2){
						num.cnt[k]++;
					}
					else{
						num.v.push_back(a[j]);
						num.cnt.push_back(1);
					}
				}
				f[i].push_back(num);
				num=f[i-1];
			}
		}
	}
	sort(a.begin()+1,a.begin()+n+1);
	vector<int> dp(n+1,0);
	for(int i=3;i<=n;i++){
		if(i!=n){
			if(a[i]==a[i+1]){
				continue;
			}
		}
		dp[i]=dp[i-1];
		for(int i=3;i<=n;i++){
		}
	}
	cout<<dp[n];
	return 0;
} 
