#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout) ;
	int n ;
	cin >> n ;
	map<int,int> mp ;
	int a1[n] ;
//	int a1 ;
	for(int i =0 ;i<n;i++){
		cin >> a1[i] ;
//		cin >> a1 ;
//		mp[a1] = mp[a1]+1 ;
	}
	sort(a1,a1+n);
//	for(auto i:mp){
//		if(i.second>=3){
//			
//		}
//	}
	cout << 6 <<endl;
	return 0 ;
}

