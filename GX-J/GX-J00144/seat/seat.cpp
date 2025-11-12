#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int s[1000],b[15][15];
bool ans=1;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int h=n*m;
	cin >> s[1];
	int num=s[1];
	for(int i=2;i<=n*m;i++){
		cin >> s[i];
	}
	sort(s+1,s+h+1,cmp);
	for(int i=1;i<=m;){
		int sum=1;
		for(int j=1;j<=n;j++){
			b[i][j]=s[sum];
			if(num==s[sum]){
				cout << i << " " << j;
				ans=0;
				return 0;
			}
			sum++;
		}
		i++;
		for(int j=n;j>=1;j--){
			b[i][j]=s[sum];
			if(num==s[sum]){
				cout << i << " " << j;
				ans=0;
				return 0;
			}
			sum++;
		}
		i++;
	}
	return 0;
}
