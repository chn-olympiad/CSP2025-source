#include <bits/stdc++.h>
using namespace std;

long long n,k,num[500050],res,vis[500050];

bool check(int s,int e){
	for(int i = s;i <= e;i ++){
		if(vis[i] == true) return false;
	}
	return true;
}
void mark(int s,int e){
	for(int i = s;i <= e;i ++){
		vis[i] = true;
	}
}
int main(){
	//   ^
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >>k;
	for(int i = 1;i <= n;i ++){
		cin >>num[i];
	}
	for(int i = 1;i <= n;i ++){
		int ans = 0;
		for(int j =i;j <= n;j ++){
			ans = 0;
			for(int p = i;p <= j;p ++){
				ans = (ans ^ num[p]);
				if(ans == k&& check(i,p)){
					res ++;
					cout << i <<" " << j << endl;
					mark(i,p);
					ans = 0;
					break;
				}
			}
		}
		
	}
	cout << res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
