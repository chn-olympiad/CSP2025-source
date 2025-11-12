//1 <= n,m <= 10;
//对于所有1<=i<=n*m,均有1<=a[i]<=100且互不相同; 

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m;
int grade[110];
int seat[20][20];

bool cmp(int x,int y){
	return x > y;
}

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> grade[i];
	
	int R = grade[1];//小R的成绩 
	sort(grade + 1,grade + n * m + 1,cmp);
	int pm;//小R的排名 
	
	for(int i = 1;i <= n * m;i++){
		if(grade[i] == R) pm = i; 
	}//优化：二分 (数据范围小可不优化) 
	//cout << pm << endl;
	
	int c = (pm + n - 1) / n;
	int r = pm % n;
	if(c % 2 == 1){//奇数列从前往后 
		if(r == 0) r = n;
		else r = r;
	}else{//偶数列从后往前 
		if(r == 0) r = 1;
		else r = n - r + 1;
	}
	
	cout << c << " " << r;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
