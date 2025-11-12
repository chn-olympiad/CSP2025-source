#include<bits/stdc++.h>

using namespace std;

bool cmp(const int &a , const int &b){
	return b > a;
}

int main(){
	int n,m;
	cin >> n >> m;
	int sum = n * m;
	int cj[sum];
	for(int i = 0;i < sum;i++){
		cin >> cj[i];
	}
	int num = cj[0];
	sort(cj,cj + sum,cmp);
	int i1 = 0,i = 0;
	int arr[n][m] = {0};
	for(int i = 0;i < n;i++){
		if(i % 2 == 0){
			for(int j = 0;j < m;j++){
				arr[i][j] = cj[i1];
				i1++;
			}
		}else if(i % 2 == 1){
			for(int j = m - 1;j >= 0;j--){
				arr[i][j] = cj[i1];
				i1++;
			}
		}
	}
	
	for(int i = 0;i < n;i++){
		if(i % 2 == 0){
			for(int j = 0;j < m;j++){
				if(arr[i][j] == num){
					i++;
					j++;
					cout << i << " " << j; 
					return 0;
				}	
			}
			
		}else if(i % 2 == 1){
			for(int j = m - 1;j >= 0;j--){
				if(arr[i][j] == num){
					i++;
					j++;
					cout << i << " " << j; 
					return 0;
				}			
			}
		}
	}
}

