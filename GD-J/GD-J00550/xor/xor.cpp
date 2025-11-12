#include <bits/stdc++.h>
using namespace std; 
const int N=5e5+5;
int zu[N]; 
int huo[N];
int cnt=0;
int sum=0;
int vis;
int main(){
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	int n,k;
	cin >> n >> k; 
	for(int i=1;i<=n;i++){
		cin >> zu[i];
		if(zu[i]==k){
			cnt++;
		}
	}
	for(int tou=1;tou<=n;tou++){
		if(tou<=vis)break;
		int l=tou;
		int r=tou+1;
		int sum=0;
		for(int i=tou;i<=n;i++){
			sum=zu[l]^zu[r];
			l++;r++;
			if(sum==k){
				cnt++;
				vis=r;
				break;
		}
		}
	}
	cout << cnt;
}

