#include <bits/stdc++.h>
using namespace std;
const int maxn = 10001;
int a1[6][maxn],a3[6][maxn],a2[6][maxn],n[maxn],ma[maxn],cha[maxn],mi[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int num1=0;
	int num2=0;
	int num3=0;
	int qwe;
	int b;
	int m;
	cin >> t;
	int sum[6]; 
	for(int i = 1;i <= t;i++){
		sum[i]=0;
		mi[i] = 10001;
		cin >> n[i];
		b = n[i]/2;
		for(int j = 1;j <= n[i];j++){
			cin >> a1[i][j] >> a2[i][j] >> a3[i][j];
			if(a1[i][j]>=a2[i][j] && a1[i][j] >= a3[i][j]){
				ma[j] = a1[i][j];
				if(a2[i][j]>a3[i][j]){
					cha[j] = a1[i][j] - a2[i][j];
				}else{
					cha[j] = a1[i][j] - a3[i][j];
				}
				num1++;
			}else if(a2[i][j]>=a1[i][j] && a2[i][j] >= a3[i][j]){
				ma[j] = a2[i][j];
				if(a1[i][j]>a3[i][j]){
					cha[j] = a2[i][j] - a1[i][j];
				}else{
					cha[j] = a2[i][j] - a3[i][j];
				}
				num2++;
			}else{
				ma[j] = a3[i][j];
				if(a2[i][j]>a1[i][j]){
					cha[j] = a3[i][j] - a2[i][j];
				}else{
					cha[j] = a3[i][j] - a1[i][j];
				}
				num3++;
			}
			sum[i]+=ma[j];
		}
		if(num1>b){
			qwe = num1-b;
			for(int q =1;q <= qwe;q++){
				for(int w = 1;w <= n[i];w++){
					if(cha[w]<mi[i]){
						mi[i] = cha[w];
						m=w;
					}
				}
				sum[i] -= mi[i];
				cha[m] = 10002;
			}
		}
		if(num2>b){
			qwe = num2-b;
			for(int q =1;q <= qwe;q++){
				for(int w = 1;w <= n[i];w++){
					if(cha[w]<mi[i]){
						mi[i] = cha[w];
						m=w;
					}
				}
				sum[i] -= mi[i];
				cha[m] = 10002;
			}
		}
		if(num3>b){
			qwe = num3-b;
			for(int q =1;q <= qwe;q++){
				for(int w = 1;w <= n[i];w++){
					if(cha[w]<mi[i]){
						mi[i] = cha[w];
						m=w;
					}
				}
				sum[i] -= mi[i];
				cha[m] = 10002;
			}
		}
	}
	for(int i =1;i <= t;i++){
		cout << sum[i] << endl;
	}
	return 0;
}
