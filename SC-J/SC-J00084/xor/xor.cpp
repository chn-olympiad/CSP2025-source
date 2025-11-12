#include<bits/stdc++.h>
using namespace std;
//特殊解法: A+B+C 
//剩下暴力解法
const int N = 5e5 + 10;
int n, k, a[N];
bool pda = true;
bool pdb = true;
bool pdc = true;
vector<int> b;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i] != 1) pda = false;
		if(!(a[i] >= 0 && a[i] <= 1)) pdb = false;
	}
	if(pda){
		if(k == 0){
			int ans = n / 2;
			printf("%d\n", ans);
		}
		else{
			printf("%d\n", n);
		}
	}
		else if(pdb){
			for(int i=1;i<=n;++i){
		if(k==0){
			if(a[i] == 0) b.push_back(i);
			else if(a[i-1] == 1){
				b.push_back(i);
				a[i] = a[i-1] = -1;
			}
		}else if(k==1){
			if(a[i] == 1) b.push_back(i);
			else if(a[i-1] == 1){
				b.push_back(i);
				a[i] = a[i-1] = -1;
			}
		}
	}
	
	printf("%d\n", b.size());
			
		
	}
	return 0;
}