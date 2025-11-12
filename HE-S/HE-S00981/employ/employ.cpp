#include<bits/stdc++.h>
#include<map>
using namespace std;
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin >> n >> m;int b=0;
	char ar[n];
	for(int i = 0;i < n;i++){
		cin >> ar[i];if(ar[i]=='1'){
			b = 1;
		}
	}
	int c[n];for(int i = 0;i < n;i++){
		cin >> c[i];
	}if(n == m){
		if(b){
			cout << 0;
		}else{sort(ar,ar+n);
			int cut = 0;int cc = 0;
			for(int i = 0;i < n;i++){
				cut = cut+c[i];cc=cc+i+1;
			}
			
			
			if(cut == cc){
				cout << 1;
			}else{
				cout << 0;
			}
		}
	}else{
		cout << 0;
	}
	return 0;
}
