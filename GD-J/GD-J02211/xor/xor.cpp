#include<bits/stdc++.h>
using namespace std;

const int SIZE = 500005;
long long sz[SIZE] = {0};
long long shu[SIZE] = {0};

int n;
long long k; 

long long js(long long a, long long b){
	long long num = 0;
	long long shuwei = 0;
	while(a != 0 || b != 0){
		if(shuwei == 0) shuwei = 1;
		else shuwei *= 2;
		if(a % 2 != b % 2) num += shuwei;
		a /= 2;
		b /= 2;
	}
	return num;
}

int dfs(int loc){
	
	long long sum = sz[loc];
	bool flag = false;
	
	if(sum == k){
		flag = true;
	}
	
	else {
	    for(int i = loc; i < n - 1; i ++){
		    sum = js(sum, sz[i + 1]);
		    if(sum == k){
			    flag = true;
			    loc = i + 1;
			    break;
		    }
	    }
	}
	if(flag == true) return loc + 1;
	else return -1;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	
	for(int i = 0; i < n; i ++){
		cin >> sz[i];
	}
	
	if(sz[n - 1] == k) shu[n - 1] = 1;
	
	for(int i = n - 2; i >= 0; i --){
		long long a = 0;
		
		int len = dfs(i);
		if(len != -1) a = 1 + shu[len];
		if(a > shu[i + 1]) shu[i] = a;
		else shu[i] = shu[i + 1]; 
	}
	
	//for(int i = 0; i < n; i ++){
	//	cout << shu[i] << " ";
	//}
	
	//cout << endl;
	
	cout << shu[0];
	
	//cout << js(1, 3);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
