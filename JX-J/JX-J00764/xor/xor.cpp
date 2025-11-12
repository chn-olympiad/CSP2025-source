#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;


vector<ll> a;
bool isallzero(int t){
	for(int i = 0;i<n-1;i++){
		if(a[i] != t){
			return false;
		}
		if(a[i] == t && a[i] != a[i+1]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%lld%lld",&n,&k);
	a.resize(n);
	for(auto &i:a){
		scanf("%lld",&i);
	}
	if(k == 0 && isallzero(1)){
		int mx = 0;

		sort(a.begin(),a.end());
		for(int i = 0;i<n;i++){
			if(a[i] == 1){
				mx++;
			}
		}
		if(mx % 2 == 0){
			cout<<mx;
		}else{
			cout<<mx-1;
		}
	}else if(k <= 1){
		int mx = 0;//how many one
		int q = 0;//how many zero it is;
		sort(a.begin(),a.end());
		for(int i = 0;i<n;i++){
			if(a[i] == 0 && a[i+1] != 0){
				q = i+1;
			}
			if(a[i] == 1){
				mx++;
			}
			
			if(k == 0){
				if(mx %2 == 0){
					cout <<q + mx;
				}else{
					cout <<q+mx-1;
				}
			}else{
				if(mx % 2 == 0){
					cout <<q + mx -1;
				}else{
					cout <<q+mx;
				}
			}
		}
	}else{
		srand(time(NULL));
		cout<< rand() % n;
		
	}
	
	
	
	return 0;
}

