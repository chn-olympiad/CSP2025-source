#include <bits/stdc++.h>

using namespace std;
bool is_polygon(int x,int y,int z){//x为小木棍数量,y长度之和，z长度最大值
	return x>=3 && y>z*2;
	}
int n;
int a[5005] = {0};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
