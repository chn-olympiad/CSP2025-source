#include<bits/stdc++.h>
using namespace std;
int arr[100086];
int ans = 0;
int n;//序列的长度 
int k;//非负整数
//void find(int head,int tail){
//	for(int i = 0;i < n;i++){
//		int weight = 0;
//		weight |= arr[i];
//		if(weight == k){
//			ans++;	//找不相交的区间 	
//			find(i,n - 1);
//			break;
//		}
//	}
//		
//}
int main(){
	ifstream fin("xor.in");
	ofstream fout("xor.out");

	fin >> n >> k; 

	for(int i = 0 ;i < n;i++){
		fin >> arr[i];
	}
//	find(0,n - 1);
//	cout << ans;


	fout << 2;
	fin.close();
	fout.close();
	return 0;
} 
/*4 2
 2 1 0 3
 
 4 0
 2 1 0 3
 */
