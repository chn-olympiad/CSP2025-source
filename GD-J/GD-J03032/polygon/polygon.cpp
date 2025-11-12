#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm> 
using namespace std;

const int g_maxn=5e5+10; 
int g_mg[g_maxn]; 
int g_n,g_ans=0;
void g_dfs(int x,int tnt,int num,int last){//当前位置。值，根数，最后一个 
	if (x>g_n){
		if (num<3)return ;
		else {
			if (tnt>2*last){
				g_ans++;
			}
			return ;
		}
	}
	else {
		g_dfs(x+1,tnt,num,last);
		last=g_mg[x]; 
		g_dfs(x+1,tnt+g_mg[x],num+1,last);
	}
}
int main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout);
	cin >>g_n;
	for (int i=1;i<=g_n;i++)cin >>g_mg[i];
	sort(g_mg+1,g_mg+1+g_n);
	g_dfs(1,0,0,0);
	cout <<g_ans;

	return 0;
} 
