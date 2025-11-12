#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int checka = 0;
	int checkb = 0; 
	int checkc = 0;
	int n,t;
	int a1[n],a2[n],a3[n];
	int num = n / 2;
	int ans[n];
	int score;
	cin >> t;
	for(int i = 0;i < t;i++){
		cin >> n;
		for(int j = 0;j < n;j++){
			for(int y = 0;y < 3;y++)
				cin >> a1[y] >> a2[y] >> a3[y];
			}
		}
	for(int i = 0;i <= n;i++){
		if(a1[i] < a1[i + 1]){
			ans[i] = a1[i];
			a1[i] = a1[i + 1];
			a1[i + 1] = ans[i];
		}
	} 
	for(int j = 0;j <= num;j++)
		score = a1[j];
	cout << score;				
//	for(int i = 0;i < n;i++){
//		if(checka == num && checkb != num && checkc != num){
//			if(a2[i] > a3[i]){
//				ans[i] == a2[i];
//				checkb++;
//			}
//			else{
//				ans[i] == a3[i];
//				checkc++; 
//				}
//		}
//		if(checkb == num && checka != num && checkc != num){
//			if(a1[i] > a3[i]){
//				ans[i] == a1[i];
//				checka++;
//			}
//			else{
//				ans[i] == a3[i];
//				checkc++;
//			}
//		}
//		if(checkc == num && checka != num && checkb != num){
//			if(a2[i] > a1[i]){
//				ans[i] == a2[i];
//				checkb++;
//			}
//			else{
//				ans[i] == a1[i];
//				checka++;
//			}
//		}
//		if(checka == num && checkb == num && checkc == num)
//			break;
//		}
//	for(int i = 0;i < n;i++)
//		score += ans[i];
//	cout << score << endl;
	return 0;
}
