#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[110];
int q[11][11];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int num;
	cin>>num;
	a[1]=num;
	int num1=1,num2=n+1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	//for(int i=1;i<=n;i++){cout<<a[i];}
	
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			q[i][j]=a[num1];
			num1++;
		}
		num1+=n;
	}
	for(int i=2;i<=m;i+=2){
		for(int j=n;j>=1;j--){
			q[i][j]=a[num2];
			num2++;
		}
		num2+=n; 
	}
	//cout<<num;
	//cout<<q[3][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(q[i][j]==num){
				cout<<i<<" "<<j;
			}
		}
	}
	//3 3 94 95 96 97 98 99 100 93 92
//2 2 98 99 100 97
//2 2 99 100 97 98
//10 10 50 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100
return 0;
}
