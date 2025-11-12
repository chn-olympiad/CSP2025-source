#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
bool cmp(int a,int b){
	return a>b; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin >> n >>m;
	for(int i=1;i<=n*m;i++){
		int tmp;
		cin >>tmp;
		vec.push_back(tmp);
		if(i==1) r=tmp;
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	int k=lower_bound(vec.begin(),vec.end(),r,cmp)-vec.begin()+1;
	//cout << k << endl;
	int u=k%(2*n);
	//cout << u << endl;
	if(u==0){
		cout << k/n << ' ' << 1;
	} else if(u==n){
		cout << k/n<< ' ' << n;
	} else if(u>n){
		cout << k/n+1 << ' '<< n-k%n+1;
	}else if(u<n){
		cout <<  k/n+1 << ' ' << k%n;
	}
	
	return 0;
} 
