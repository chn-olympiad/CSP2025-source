#include <bits/stdc++.h>
using namespace std;
int order[12399][12399], grades[12399];
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	//////////////////////////////////////////////////////////////////////
	//输入m、n 
	int n, m;
	cin >> n >> m;
	//////////////////////////////////////////////////////////////////////
	//对grades进行 输入 和 从大到小的排序 、获取小R的成绩 
	for(int i = 1; i <= m * n; i++){				//入 
		cin >> grades[i];
	} 
	int R = grades[1];								//R
	sort(grades+1, grades+(m*n)+1, cmp);			//排 
	//////////////////////////////////////////////////////////////////////
	//维护order数组，将grades按顺序录入order 
	int cnt = 0;//当前编号 
	for(int i = 1; i <= m; i += 2){//列数 
		for(int j = 1; j <= n; j++){//奇数列：自上而下递增 
			cnt++;
			order[j][i] = grades[cnt];
		}
		for(int j = n; j >= 1; j--){//偶数列：自上而下递减 
			cnt++;
			order[j][i+1] = grades[cnt];
		}
	}
	//////////////////////////////////////////////////////////////////////
	//双for遍历，寻找小R的成绩，找到后输出，先列后行 
	for(int i = 1; i <= m; i++){//列 
		for(int j = 1; j <= n; j++){//行 
			if(order[j][i] == R){
				cout << i << " " << j;
				break;
			}
		} 
	}
	//////////////////////////////////////////////////////////////////////
	//打桩测试
	/*(for(int i = 1; i <= m * n; i++){
		cout << grades[i] << " ";
	} */ 								 //grades没问题 
	/*for(int j = 0; j <= n; j++){//行 
		for(int i = 0; i <= m; i++){//列 
			cout << order[i][j] << " ";
		} 
		cout << endl;
	}*/
	//////////////////////////////////////////////////////////////////////
	fclose(stdin);
	fclose(stdout);
	return 0;
}









