#include <bits/stdc++.h> 
using namespace std;
int cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;    //测试数据组数 
	int m[t+1];  //保存测试结果 
	cin >> t;
    for(int y = 0;y<t;y++){
    	int n;    //新成员数量
		int s = 0;
	    cin >> n;
		for(int i = 1;i<=n;i++) {    //输入每名成员的满意程度 
			int a[4] = {0};
			for(int j = 0;j<3;j++){
				cin >> a[j];
			}
			sort(a,a+4,cmp) ;
			s = s + a[0];        //记录每名学生的满意度 
		}
		m[y] = m[y] + s;
	}
	for(int i = 0;i<t;i++){
		cout << m[i] << endl;   //输出所有值 
	}
	return 0;
}
   






