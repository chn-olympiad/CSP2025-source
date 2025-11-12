#include <bits/stdc++.h>
using namespace std;
long long n,k=2;
long long a[6000];
long long temp[6000];
bool b[6000]={false};

void calc(){
	for (int i = 1 ; i <= k ; i ++ ){
		cout <<temp[i]<<" ";
	}
	cout << endl;
	return;
}
void dfs(long long pos){
	b[pos]=true;
	//cout << pos << endl;
	if (pos >= k){
		calc();
		return;  
	}
	for (int i = 1;i <= n;i++){
		if (!b[i]){
			b[i] = true;
			temp[pos]=a[i];
			dfs(pos+1);
			b[i] = false;
		}
		
	}	
	return 0;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (long long i = 1 ; i <= n ; i ++ ){
		cin >> a[i];
	}
	dfs(1);
	return 0;
}

