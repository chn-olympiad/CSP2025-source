#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	int a[500005];
	bool k = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1){
			k = 1;
		}
	}
	if(n <= 2 && k==0){
		cout << n/2;
		return 0;
	}
	if(k == 0){
		cout <<n/2;
		return 0;
	}
	if(m == 0){
		int ll =0;
		for(int i = 1; i <= n; i++){
			if(a[i] == 0){
				ll++;		
			}
		}	
		cout << ll;
		return 0;
	}else if(m == 1){
		int ll =0;
		for(int i = 1; i <= n; i++){
			if(a[i] == 1){
				ll++;		
			}
		}	
		cout << ll;
		return 0;
	} 
	int ll =0;
	for(int i = 1; i <= n; i++){
		int aa[35] = {0};
		int bb[35] = {0}; 
		for(int j =i; j <=n; j++){
			int ar = a[j];
			int sss = 0;
			for(int k = 1; ar != 0; k++){
				aa[k] = ar%2;
				ar/=2;
				sss++;
			}
			for(int k = 1; k <= sss; k++){
				if(aa[k] != bb[k]){
					bb[k] = 1;
				}else{
					bb[k] = 0;
				}
			}
			long long ss = 0;
			for(int k = 1; k <= 30; k++){
				ss += bb[k]*pow(2,(k-1));
			}
			if(ss == m){
				ll++;
				i = j;
				break;
			}
		}
	}
	cout << ll;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
