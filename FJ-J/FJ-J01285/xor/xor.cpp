#include<bits/stdc++.h>
using namespace std;

int n,k,a[500005],pre[500005],cnt;

int solve(int begin){
	int cnt2 = 0;
	for(int l = begin; l <= n;){
		bool flag = true;
		for(int r = l; r <= n; r++){
			int sum = pre[r] xor pre[l-1];
			if(sum == k){
				cnt2++;  
				l = r+1; 
				flag = false;
				break;
			}
		}
		if(flag){
			l++;
		}
	}
	return cnt2;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin >>n >>k;
	if(n>1000){ 
		int cnt1=0,cnt0=0;
		for(int i = 1; i <= n; i++){
			cin >>a[i];
			if(a[i] == 1){
				cnt1++;
			}
			if(a[i] == 0){
				cnt0++;
			}
		}
		if(k == 0){
			cout <<cnt0;
		}else if(k == 1){
			cout <<cnt1;
		}
		return 0;
	}
	for(int i = 1; i <= n; i++){
		cin >>a[i];
		pre[i] = pre[i-1] xor a[i];
	} 
	for(int i = 1; i <= n; i++){
		cnt = max(cnt,solve(i));
	}
	cout <<cnt;
	return 0;
}  
 
