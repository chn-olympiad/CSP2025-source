#include <bits/stdc++.h>
using namespace std;

struct M{
	int nl;
	int ml;
};	

M N[501];int L[500],use[500],xb[500];

bool doin[500];
long long m;

int cmp(int x , int y){
	//cout << x << ' ' << y << endl;
	return N[x].ml < N[y].ml;
}

int Find(int i , int m2 , int nummax){
	if (i == 0 or m2 <0) if (nummax == m-1) return 1;
	long long out = 0;
	for (int j=0;j<=m2;j++){
		out+= Find(i-1 , min(j-1 , L[xb[i-1]]) , nummax+1);
	}
	return out;
}
int main(){
	long long n;
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin >> n >> m;
	string nums;
	cin >> nums;
	for (int i=0;i<nums.length();i++) N[i].nl = nums[i] - '0';
	for (int i=1;i<nums.length();i++) N[i].nl = nums[i] - '0' + N[i-1].nl;
	for (int i=0;i<n;i++) cin >> N[i].ml;
	int xb[n];
	for (int i=0;i<n;i++) xb[i] = i;
	sort(xb, xb+n , cmp);
	int IN1 = n-1 , IN2 = n;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (N[j].nl <= N[xb[i]].ml){
				use[xb[i]] = j+1;
				L[xb[i]] ++;
				
			}
		}
	}
	cout << Find(n-1,L[xb[n-1]],0);
	//for (int i=0;i<n;i++) cout << use[i]; 
	return 0;
}
	
