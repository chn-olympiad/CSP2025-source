#include<bits/stdc++.h>
using namespace std;
const int MOD = 5000000500; 
const int MAX = 5050;
int n;
int a[MAX];
void dfs(int idx,int cnt,int sum,int Max){
	 
	
}

int main(){
	
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cout << 
	cin >> n
	bool type=true;
	for(int i = 1;i<= n;i++){
		cin >> a[i];
		if(a[i]>1)
			type=false; 	
	}
	if(n < 3){
		cout << 0 << endl;
	}else if(n==3){
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2],a[3])){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;
		}
	}else if(n <=20){
		dfs(1,0,0,0)
		cout << ans << endl;
	}
	
	
	
	else if (type){
		int mul = 1;
		for(int i = 1;i<=n;i++){
			mul=(mul*2)%MOD;
		}
		cout << (mul+MOD-1-n-n*(n+1)/2)%MOD<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

