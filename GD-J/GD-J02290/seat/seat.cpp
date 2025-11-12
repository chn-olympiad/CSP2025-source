#include <bits/stdc++.h>
using namespace std;
int n,m;
int nums[1000];
int a;
int kk[20][20]={-1};
bool cmps(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> nums[i];
	}
	a=nums[1];
	sort(nums+1,nums+n*m+1,cmps);
	int numk;
	for(int i=1;i<=n*m;i++){
		if(nums[i]==a){
			numk=i;
		}
	}
	int o=0;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				o++;
				kk[j][i]=nums[o];
			}
		}
		else{
			for(int j=m;j>0;j--){
				o++;
				kk[j][i]=nums[o];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(kk[i][j]==nums[numk]){
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
	return 0;
}
