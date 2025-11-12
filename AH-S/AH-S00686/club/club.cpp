#include<bits/stdc++.h>
using namespace std;
int a[1010][5], sr[10010][5];
struct node{
	int sum, num;
}x1[1010], x2[1010], x3[10010], x12[1010], x22[1010], x32[010];
bool tr[1010];
bool cmp(node a, node b){
	return a.sum > b.sum;
}
int main(){
	//freopen("club.in", "r", stdin);
	//freopen("club.out", "r", stdout);
	int t;
	cin >> t;
	while(t--){
		int n, num1 = 0, num2 = 0, num3 = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][1] > a[i][2] && a[i][1] > a[i][3] && a[i][2] > a[i][3]){
				sr[i][1] = 1, sr[i][2] = 2, sr[i][3] = 3;
				x1[++num1].sum = a[i][1];
				x1[num1].num = i;
				x12[num1].sum = a[i][2];
				x12[num1].num = i;
			}
			if(a[i][1] > a[i][2] && a[i][1] > a[i][3] && a[i][2] < a[i][3]){
				sr[i][1] = 1, sr[i][2] = 3, sr[i][3] = 2;
				x1[++num1].sum = a[i][1];
				x1[num1].num = i;
				x12[num1].sum = a[i][3];
				x12[num1].num = i;
			}
			if(a[i][1] < a[i][2] && a[i][1] > a[i][3] && a[i][2] > a[i][3]){
				sr[i][1] = 2, sr[i][2] = 1, sr[i][3] = 3;
				x2[++num2].sum = a[i][2];
				x2[num2].num = i;
				x22[num1].sum = a[i][1];
				x22[num1].num = i;
			}
			if(a[i][1] < a[i][2] && a[i][1] < a[i][3] && a[i][2] > a[i][3]){
				sr[i][1] = 3, sr[i][2] = 1, sr[i][3] = 2;
				x2[++num2].sum = a[i][2];
				x2[num2].num = i;
				x22[num1].sum = a[i][3];
				x22[num1].num = i;
			}
			if(a[i][1] > a[i][2] && a[i][1] < a[i][3] && a[i][2] < a[i][3]){
				sr[i][1] = 2, sr[i][2] = 3, sr[i][3] = 1;
				x3[++num3].sum = a[i][3];
				x3[num3].num = i;
				x32[num1].sum = a[i][1];
				x32[num1].num = i;
			}
			if(a[i][1] < a[i][2] && a[i][1] < a[i][3] && a[i][2] < a[i][3]){
				sr[i][1] = 3, sr[i][2] = 2, sr[i][3] = 1;
				x3[++num3].sum = a[i][3];
				x3[num3].num = i;
				x32[num1].sum = a[i][2];
				x32[num1].num = i;
			}
		}
		sort(x1 + 1, x1 + num1 + 1, cmp);
		sort(x2 + 1, x2 + num2 + 1, cmp);
		sort(x3 + 1, x3 + num3 + 1, cmp);
		if(num1 <= n / 2 && num2 <= n / 2 && num3 <= n / 2){
			int sum = 0;
			for(int i = 1; i <= num1; i++){
				sum += x1[i].sum;
			}
			for(int i = 1; i <= num2; i++){
				sum += x2[i].sum;
			}
			for(int i = 1; i <= num3; i++){
				sum += x3[i].sum;
			}
			cout << sum << "\n";
		}
		if(num1 > n / 2){
			int sum = 0;
			for(int i = 1; i <= num2; i++){
				sum += x2[i].sum;
			}
			for(int i = 1; i <= num3; i++){
				sum += x3[i].sum;
			}
			for(int i = 1; i <= n / 2; i++){
				for(int j = n / 2 + 1; j <= num1; j++){
					if(a[x1[i].num][sr[x1[i].num][2]] + x1[i].sum < x1[j].sum + a[x1[j].num][sr[x1[j].num][2]]){
						swap(x1[i].sum, x1[j].sum);
						swap(x1[i].num, x1[j].num);
					}
				}
			}
			for(int i = 1; i <= n / 2; i++){
				sum += x1[i].sum;
			}
			for(int i = n / 2 + 1; i <= num1; i++){
				sum += a[x1[i].num][sr[x1[i].num][2]];
			}
			cout << sum << "\n";
		}
		if(num2 > n / 2){
			
			int sum = 0;
			for(int i = 1; i <= num1; i++){
				sum += x1[i].sum;
			}
			for(int i = 1; i <= num3; i++){
				sum += x3[i].sum;
			}
			for(int i = 1; i <= n / 2; i++){
				for(int j = n / 2 + 1; j <= num2; j++){
					if(a[x2[i].num][sr[x2[i].num][2]] + x2[i].sum < x2[j].sum + a[x2[j].num][sr[x2[j].num][2]]){
						swap(x2[i].sum, x2[j].sum);
						swap(x2[i].num, x2[j].num);
					}
				}
			}
			for(int i = 1; i <= n / 2; i++){
				sum += x2[i].sum;
			}
			for(int i = n / 2 + 1; i <= num2; i++){
				sum += a[x2[i].num][sr[x2[i].num][2]];
			}
			cout << sum << "\n";
		}
		if(num3 > n / 2){
			int sum = 0;
			for(int i = 1; i <= num1; i++){
				sum += x1[i].sum;
			}
			for(int i = 1; i <= num2; i++){
				sum += x2[i].sum;
			}
			for(int i = 1; i <= n / 2; i++){
				for(int j = n / 2 + 1; j <= num3; j++){
					if(a[x3[i].num][sr[x3[i].num][2]] + x3[i].sum < x3[j].sum + a[x3[j].num][sr[x3[j].num][2]]){
						swap(x3[i].sum, x3[j].sum);
						swap(x3[i].num, x3[j].num);
					}
				}
			}
			for(int i = 1; i <= n / 2; i++){
				sum += x1[i].sum;
			}
			for(int i = n / 2 + 1; i <= num3; i++){
				sum += a[x3[i].num][sr[x3[i].num][2]];
			}
			cout << sum << "\n";
		}
	}
	return 0;
}
