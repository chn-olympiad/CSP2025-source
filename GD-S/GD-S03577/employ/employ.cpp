#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int n,m,k,t,c[100005],ans;string h;
bool s[100005], o[10005];int l[10005];


int dfs(int a,bool op[],int kl[]){
	int num =0; 
	if(a<n){
		for(int i =1;i<=n;i++){
			if(!op[i]){
				op[i] =1;
				kl[a+1] = i;
				num = (num+dfs(a+1,op,kl))%MOD;
				kl[a+1] = 0;
				op[i] = 0;
			}
		}
		return num;
	}
	else{
		int ds = 0,sum = 0,oi = 1;
		for(int i =1;oi<=n;i++,oi++){
			int j = kl[oi];
			if(ds>=c[j]){
				ds++;i--;
				continue;
			}
			else{
				if(s[i]){
					sum++;
				}
				else ds++;
			}
		//	cout << sum <<" "<<m << "\n";
		}
		if(sum>=m){
			for(int i =1;i<=n;i++){
				cout << kl[i];
			}cout << endl;
			return 1;
		}
	
	}
	
}


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m>>h;
	for(int i =0;i<h.size();i++){
		if(h[i] == '0')s[i] = 0;
		else s[i] =1;
	}
	for(int i =1;i<=n;i++){
		cin >> c[i];
		
	}
	cout<<dfs(0,o,l);
	
	
	
	return 0;
}
