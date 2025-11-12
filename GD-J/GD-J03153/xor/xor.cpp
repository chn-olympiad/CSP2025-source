#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	long long a[100005];
	int num[100005] = {},ans = 0;
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int maps[100005] = {};
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			int sum = 0;
		   	for(int x = i;x <= j;x++){
		   		if(maps[x] == 1) sum++;
		   		maps[x] = 1;
		   		ans ^= a[x];
		   	}
		   	if(ans == k) num[sum]++;
		}
	}
	for(int i = 1;i <= n;i++){
		if(num[i]){
		    cout << num[i];
			return 0;	
		}
	}
	return 0; 
}
