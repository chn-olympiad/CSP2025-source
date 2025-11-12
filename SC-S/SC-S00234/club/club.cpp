#include<bits/stdc++.h>
using namespace std;

int m[100000][3];
int max_n(int b1, int b2, int b3, int c) {
	int hs[3], temp = 0, a;
	hs[0] = b1;
	hs[1] = b2;
	hs[2] = b3;
	for (int i = 0; i < 3; i = i)
		if (hs[temp] >= hs[i] && temp != c) {
			i++;
			a = temp;
		} else if (hs[temp] <= hs[i])
			temp++;
	return a;
}
int pc(int n2, int n1) {
	for (int i = 0; i < 3; i++) {
		if (i != n2 && i != n1)
			return i;
	}

}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out" , "w",stdout);
	int times;//数据组数
	cin >> times;
	int  s = 0, p[3];
	float n;
	for (int yyy = 0; yyy < times; yyy++) {
		//
		s = 0;
		cin >> n;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < 3; k++)
				cin >> m[j][k]; //输入
		for (int i = 0; i < n; i++) {
			if (p[max_n(m[i][0], m[i][1], m[i][2], -1)] >= n / 2) {
				p[max_n(m[i][0], m[i][1], m[i][2], -1)]++;
				s += m[i][max_n(m[i][0], m[i][1], m[i][2], -1)];
			} else if (p[max_n(m[i][0], m[i][1], m[i][2], p[max_n(m[i][0], m[i][1], m[i][2], -1)])] >= n / 2) {
				p[p[max_n(m[i][0], m[i][1], m[i][2],-1), p[max_n(m[i][0], m[i][1], m[i][2], -1)]]]++;
				s += m[i][max_n(m[i][0], m[i][1], m[i][2],-1), p[max_n(m[i][0], m[i][1], m[i][2], -1)]];
			} 
			else
			{
				p[pc(max_n(m[i][0], m[i][1], m[i][2], -1), max_n(m[i][0], m[i][1], m[i][2],-1))]++;
				s += m[i][pc(max_n(m[i][0], m[i][1], m[i][2],-1), -1), max_n(m[i][0], m[i][1], m[i][2],-1),max_n(m[i][0], m[i][1], m[i][2],-1)];
			}
		}
		cout << s << endl;
		s = 0;
	}
}
