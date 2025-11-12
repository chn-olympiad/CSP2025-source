#include<bits/stdc++.h>
using namespace std;
struct node{
	int num, id;
}a[100010][4];
int T, n, f[4], cnt, b[100010], idx; // f-> 学院人数 b-> a[i]去的学院 
void ts(int i)
{
	//调试 
	cout << "----------------" << endl;
	for(int j = 1; j < 4; j ++) cout << f[j] << " ";
	cout << endl << cnt << endl << b[i] << " " << a[i][b[i]].id << endl << idx << endl << "----------------" << endl;
}
void sortm(int i)
{
	int e1 = a[i][1].num, v1 = a[i][1].id;
	int e2 = a[i][2].num, v2 = a[i][2].id;
	int e3 = a[i][3].num, v3 = a[i][3].id;
	if(e1 > e2 && e3 > e1) // 3 > 1 > 2
	{
		a[i][1].num = e3, a[i][1].id = v3, a[i][2].id = v1, a[i][2].num = e1, a[i][3].num = e2, a[i][3].id = v2;
	}else if(e2 > e3 && e3 > e1){ // 2 > 3 > 1
		a[i][1].num = e2,a[i][1].id = v2,a[i][2].num = e3,a[i][2].id = v3,a[i][3].id = v1,a[i][3].num = e1;
	}else if(e1 > e3 && e3 > e2){ // 1 > 3 > 2
		a[i][2].num = e3, a[i][2].id = v3, a[i][3].num = e2, a[i][3].id = v2;
	}else if(e2 > e1 && e1 > e3){ // 2 > 1 > 3
		a[i][1].num = e2, a[i][1].id = v2, a[i][2].num = e1, a[i][2].id = v1;
	}else if(e3 > e2 && e2 > e1){ // 3 > 2 > 1
		a[i][1].num = e3, a[i][1].id = v3, a[i][2].id = v2, a[i][2].num = e2, a[i][3].num = e1, a[i][3].id = v1;
	}
}
bool cmp(node x, node y)
{
	return x.num > y.num;
}
void dfs(int i, int bi)
{
	int maxn = cnt + a[i][bi + 1].num, idj = i;
	for(int j = 1; j < i; j ++) // 找最小 
	{
		if(a[j][b[j]].id == a[i][bi].id && j != i){ // 学院相同 
			if(cnt - a[j][b[j]].num + a[j][b[j] + 1].num + a[i][bi].num > maxn) 
			{
				maxn = cnt - a[j][b[j]].num + a[j][b[j] + 1].num + a[i][bi].num;
				idj = j; // 标记 
			}
		}
//		if(j == i)
//		{
//			if(cnt + a[i][b[j] + 1].num > maxn) 
//			{
//				idj = j; // 标记 
//			}
//		}
	}
	bool fe1 = false, fe2 = false;
	idx = idj;
	if(idj)
	{
		fe1 = true;
		if(f[a[idj][b[idj] + 1].id] < n / 2) // aj下一志愿还有位置
		{
			b[i] = bi;
			cnt = cnt + a[i][bi].num - a[idj][b[idj]].num + a[idj][b[idj] + 1].num;
			b[idj] += 1;
			f[a[idj][b[idj]].id] ++;
			fe2 = true;
		}
	}
	if(fe1 && !fe2) dfs(idj, b[idj] + 1); // 有比当前的小的 
	else if(!fe1) dfs(i, bi + 1); // 没有比当前小的 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T --)
	{
		cnt = 0;
		memset(f, 0, sizeof f);
		cin >> n;
		for(int i = 1; i <= n; i ++)
		{
			a[i][1].id = 1;
			a[i][2].id = 2;
			a[i][3].id = 3;
		}
		for(int i = 1; i <= n; i ++)
		{
			cin >> a[i][1].num >> a[i][2].num >> a[i][3].num;
			sortm(i);
			b[i] = 1;
			if(f[a[i][1].id] < n / 2)
			{
				idx = i;
				f[a[i][1].id] ++;
				cnt += a[i][1].num;
				//ts(i); // ts
				continue;
			}
			// 第一志愿人数满了 
			dfs(i, b[i]);
			//ts(i); // ts
		}
		cout << cnt << "\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

