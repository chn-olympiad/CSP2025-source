#include<bits/stdc++.h>
using namespace std;

int n, m;	//参与者，希望 
int endr[N];		//面试难度 
int pati[N];		//耐心上限 

int inline read(){
	int x=0, f=1;
	char ch = getchar();
	if(ch<'0' || ch>'9'){
		if(ch == '-'){
			f = -1;
			ch = getchar();
		}
	}
	if(ch>='0' && ch <='9'){
		x = x*10 + ch -'0';
		ch = getchar();
	}
	return x*f;
}

int main(){
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	n = read();		//面试人数 
	m = read();		//希望录用
	string s;
	cin >> s;
	
	bool pan = true;
	for(int i=0; i<n; i++){
		endr[i] = s1[i];
		if(s[1] == 1)  pan = false;
		cin >> pati[i];
	}
	
	long long ans = 0;
	if(pan == true){
		ans = 1;
		for(int i=n; i>=1; i--){
			ans = ans*i;
		}
		cout << ans;
		return 0;
	}
	
	
	
	return 0;
}
