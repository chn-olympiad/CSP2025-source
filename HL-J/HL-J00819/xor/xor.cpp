#include <bits/stdc++.h>
using namespace std;

int ans;
int n,k;
vector<int> a;
map<vector<int>,int> dp;

int len(int a[]){
	return sizeof(a)/4;
}

int cal_k(int tmp[],int i){
	if(len(tmp) == 0){
		return tmp[0];
	}
	
	for(int i = 0;i<len(tmp);i++){
		
	}
	
	
	int new_tmpp[len(tmp)+1]
	cal_k();
}


int main(){
	
	cin>>n>>k;
	a.resize(n);
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		if(a[i] != k){
			a[i] = tmp;
		}else{
			ans++;
		}
	}
	
	sort(a.begin(),a.end());
	
	


	
	return 0;
}