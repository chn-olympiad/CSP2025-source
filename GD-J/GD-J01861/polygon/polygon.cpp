#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int arr[100005];
int brr[100005];
int num = 1;
bool s(int f,int we){
	for(int i = 1;i <= f;i++){
		if(we == brr[i]){
			return false;
		}
	}return true;
}
int tal(int n,int m,int agrr[10005]){
	int ant = 0;
	for(int i = n;i <= m;i++){
		if(s(num,arr[i])){
			ant += arr[i];
		}		
	}return ant;
}
int m(int n,int m,int hrr[1005]){
	int ma = 0;
	for(int i = n;i <= m;i++){
		if(arr[i] > ma and s(num,arr[i])){
			ma = arr[i];
		}
	}return ma;
}
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> arr[i];	
	}
	int cnt = 0;
	int krr[1002];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int k = i;k <= j;k++){
				krr[num] = arr[k];
				num++;				
				if(j - i >= 3 and tal(i,j,krr) > 2 * m(i,j,krr)){
					cnt++;
					for(int q = i;q <= j;q++){
						if(s(num,arr[q])){
							cout << arr[q]<<' ';
						}
						
					}cout << endl;
				}
			}
			num = 0;
		}	
	}
	cout << cnt % 908244353;
	return 0;
}
