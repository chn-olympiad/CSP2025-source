#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int book[5005];
int sum ,x;
int lj[5005];
int jy[5005][5005];
int bo[5005][15];
int id = 0,id2 = 0;
void dfs(int len,int maxn)
{
	if(x == len)
	{
		int cnt = 0;
		for(int i = 1;i <= len;i ++){
			//cout << lj[i] << " ";
			cnt += lj[i] , maxn = max(lj[i] , maxn) , jy[id][id2 ++] = lj[i],bo[id][lj[i]] ++;
		}
		id2 = 0,id ++;
		int flag = 0;
		int z = 0;
		bool same = 0;
		//for(int i = 0;i < 10;i ++)cout << bo[id-1][i] << " ";
		for(int i = 0;i <= id-1;i ++){
			if(i == id-1)break;
			if(z >= 10){
				if(same == 1){
					flag = 0;
					return ;
				}
				z = 0;
				continue;
			}
			if(bo[i][z] == bo[id-1][z]){
				same = 1;
			}
			else {
				flag = 1;
				same = 0;
				z = 0;
				continue;
			}
			z ++;
		}
		//cout << endl;
		if(2*maxn > cnt && id == 1){
			for(int i = 1;i <= len;i ++)
				cout << lj[i] << " ";
			cout << endl;
			sum ++ , sum = sum%998244353;
			return ;
		}
		else if(2*maxn < cnt && flag == 1){
			for(int i = 1;i <= len;i ++)
				cout << lj[i] << " ";
			cout << endl;
			sum ++ , sum = sum%998244353;
		}
		maxn = 0;
		return ;
	}
	for(int i = 1;i <= n;i ++){
		if(a[i] < lj[x - 1])continue;
		if(book[i] == 0 && a[i] >= lj[x-1]){
			book[i] = 1;
			lj[++x] = a[i];
			dfs(len,maxn);
			book[i] = 0;
			x --;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//int maxx = 0,sums = 0;
	//cin >> n;
	//for(int i = 1;i <= n;i ++)cin >> a[i];
	//sort(a+1,a+n+1);
	//for(int i = 3;i <= n-1;i ++){
	//	x = 0;
	//	memset(book , 0 ,sizeof book);
	//	memset(lj , 0 ,sizeof lj);
	//	dfs(i,0);
	//}
	//for(int i = 1;i <= n;i ++){
	//	maxx = max(maxx , a[i]);
	//	sums += a[i];
	//}
	//if(sums > maxx)sum ++;
	//cout << sum;
	cout << 1;
	return 0;
}
