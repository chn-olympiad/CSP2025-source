#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[110];
int mp[20][20];

bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n * m;i++){
		cin>>a[i];
	}
	int k = a[1];
	sort(a+1,a+1+(n * m),cmp);
	int p = 1;
	bool f = 0;
	for(int i = 1;i <= m;i++){
		if(f == 1){
			break;
		}
		if(i % 2 == 1){
			for(int j = 1;j <= n;j++){
				mp[j][i] = a[p++];
			}
		}else{
			for(int j = n;j >= 1;j--){
				mp[j][i] = a[p++];
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(mp[i][j] == k){
				cout<<j<<' '<<i<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


