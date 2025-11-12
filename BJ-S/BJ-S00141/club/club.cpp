#include <bits/stdc++.h>
using namespace std;
struct num{
	int clu,cha;
};
int T, n, fin, a, b, c, book[100010];
num stu[100010];
int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--) {
		fin = 0;
		int ma[5] = {0,0,0,0,0};
		num stu[100010];
		cin >> n;
		for(int i = 1; i <= n ;i ++ ) {
			cin >> a >> b >> c;
			
			if (a > max(b,c) ){//如果a最大
				stu[i].clu = 1;//记录ta在这个club
				stu[i].cha = a - max(b,c);//如果a这个俱乐部人数超过了一半,判断是否移开这个学生
				ma[1] ++;
				fin += a;
			}
			if (b > max(a,c) ){
				stu[i].clu = 2;
				stu[i].cha = b - max(a,c);//如果b这个俱乐部人数超过了一半,判断是否移开这个学生
				ma[2] ++;
				fin += b;
			}
			if (c > max(a,b) ){
				stu[i].clu = 3;
				stu[i].cha = c - max(a,b);//如果b这个俱乐部人数超过了一半,判断是否移开这个学生
				ma[3] ++;
				fin += c;
			}
		}
		int da = 0,xia= 0;
		for(int i = 1;i <= 3; i ++ ) if(ma[i] > n/2) da = i;
		//这里找到人数超过的那个
		if(da == 0) {
			cout << fin << endl;
		}else {
			for(int i = 1; i <= n; i ++) {
				if(stu[i].clu == da){
					xia ++;
					book[xia] = stu[i].cha;
				}
			}
			//统计出来每个人如果换地方损失的满意度
			
			sort(book + 1,book + 1 + xia);
			//按照从小到大排序
			
			int ls1 = 0;
			while(ma[da] > n/2 ){
				ls1 ++;
				fin -= book[ls1];
				ma[da]--;
			}
			//直接减去满意度最小的
			cout << fin << endl;
		}
	}
	return 0;
}