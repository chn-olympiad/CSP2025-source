#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int m,n;
int fen[11][11];
int flag=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	int len=m*n;
	int num[len];
	int num1[len];
	for(int i = 0;i<len;i++){
		cin>>num[i];
	}
	int u=num[0];
	sort(num,num+len);
	for(int i = 0;i<len;i++){
		num1[i]=num[len-i-1];
	}
	for(int i = 1;i<=m;i++){
		if(i%2!=0){
			for(int j = 1;j<=n;j++){
				fen[j][i]=num1[flag];
				flag++;
			}
		}
		else{
			for(int j = n;j>=1;j--){
				fen[j][i]=num1[flag];
				flag++;
			}
		}
	}
	bool pan=0;
	for(int i = 1;i<=m;i++){
		if(pan) break;
		for(int j = 1;j<=n;j++){
			if(fen[j][i]==u){
				cout<<i<<' '<<j;
				pan=1;
				break;
			}
		}
	}
	return 0;
}
