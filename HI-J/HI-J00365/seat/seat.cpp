#include<bits/stdc++.h>
using namespace std;

int n,m,num[101],xxx[11][11],a,temp;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int sum = n*m;
	for(int i=1;i<=sum;i++){
		cin >> num[i];
		if(i == 1)a = num[i];
	}
	for(int i=1;i<=sum;i++){
		for(int j=i;j<=sum;j++){
			if(num[j] > num[i]){
				temp = num[j];
				num[j] = num[i];
				num[i] = temp;
			}
		}
	}
	int k = 1;
	for(int i=1;i<=m;i++){
		if(i % 2 != 0){
			for(int j=1;j<=n;j++){
				xxx[i][j] = num[k++];
				if(xxx[i][j]==a)cout << i << " " << j;		
			}
		}else if(i % 2== 0){
			for(int j=n;j>=1;j--){
				xxx[i][j] = num[k++];
				if(xxx[i][j]==a)cout << i << " " << j;		
			}
		}
	}
	return 0;
} 


