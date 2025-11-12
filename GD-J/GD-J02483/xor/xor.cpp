#include<bits/stdc++.h>
using namespace std;
namespace specialA{
	void solve(int n){
		cout << (n/2);
	}
}
namespace specialB{
	void solve0(int n,int k,vector<int> a){
		int cnt = 0;
		bool flag = 0;
		for(auto i : a){
			if(i){
				if(!flag){
					flag = 1;
				}
				else{
					flag = 0;
					cnt++;
				}
			}
		}
		cout << cnt;
	}
	void solve1(int n,int k,vector<int> a){
		int cnt = 0;
		for(auto i : a){
			if(i)cnt++;
		}
		cout << cnt;
	}
	void solve(int n,int k,vector<int> a){
		if(k==0)solve0(n,k,a);
		else solve1(n,k,a);
	}
}
	
int n,k;
vector<int> a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		int x;cin >> x;
		a.push_back(x);
	}
	if(k==0){
		specialA::solve(n);
		return 0;
	}
	if(k<=1){
		specialB::solve(n,k,a);
	}
	return 0;
}
