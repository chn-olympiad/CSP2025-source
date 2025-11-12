#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int c[maxn];

void mymain(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> c[i];
	if(k <= 1){
		int a = 0, b = 0, lian = 0, qu = 0;
		for(int i = 1; i <= n; i++){
			if(c[i] == 0) a++;
			else b++;
			
			if(c[i] == 1 && i < n) lian++;
			else{
				if(i == n && c[i]) lian++;
				qu += lian / 2;
				lian = 0;
			}
		}
		if(k == 0){
			if(a == 0){                            // k = 0, a[i] 均为 1
				cout << qu << endl;
				return;
			}else if(b == 0){                     // k = 0, a[i] 均为0,  
				cout << n << endl;
				return;                 
			}else{                               // k = 0, a[i] 1、0均有 
				int ans = a + (qu);
				cout << ans;
				return;
			}
		}else{
			if(b == 0){                          // k = 1, a[i] 均为0 
				cout << 0 << endl;
				return;  
			}else if(a == 0){                    //k = 1, a[i] 均为1 
				cout << n << endl;
				return;
			}else{                              //k = 1, a[i] 1、0均有 
				cout << b << endl;
				return;
			}
		}
	}
	
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
//	int n;
//	cin >> n;
//	while(n--){	
		mymain();
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


//#Shang4Shan3Ruo6Shui4












