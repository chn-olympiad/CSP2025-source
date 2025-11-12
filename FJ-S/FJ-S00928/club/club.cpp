#include<bits/stdc++.h>
using namespace std;
int a[10010],b[10010],c[10010];
int an,bn,cn;
int acous,bcous,ccous;

int n = 0;
int n2;
int secondans;
int endans;
int ans[10010][3];
void dfs(int m){
	
	if(m > n){
		secondans = an + bn + cn;
		
//		if(n == 2){
//		cout << endl;
//			for(int i = 0;i < n;i ++){
//				for(int j = 0;j < 3;j ++){
//					cout << ans[i][j] << " ";
//				}
//				cout << endl;
//			}
//			cout << an << " " << bn << " " << cn << endl
//			 	<< endans << " " << secondans << " " << m;
//			getchar();
//			system("cls");
//		}
		
//			cout << endans << " ";
		return;
	}
	if(acous < n2){
		//cout << "in the a\n";
		int count = a[m];
		ans[m][0] = count;
		an += a[m];
		acous ++;
		dfs(m + 1);
		endans = max(endans,secondans);
		ans[m][0] -= count;
		an -= a[m];
		acous --;
	}
	if(bcous < n2){
		int count = b[m];
		ans[m][1] = count;
		bn += b[m];
		//cout << b[m] << " " << m << " | ";
		bcous ++;
		dfs(m + 1);
		endans = max(endans,secondans);
		ans[m][1] -= count;
		bn -= b[m];
		bcous --;
	}
	if(ccous < n2){
		//cout << "in hte c\n";
		int count = c[m];
		ans[m][2] = count;
		cn += c[m];
		ccous ++;
		dfs(m + 1);
		endans = max(endans,secondans);
		ans[m][2] -= count;
		cn -= c[m];
		ccous --;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int soun = 0;
	cin >> soun;
	for(int ins =0;ins < soun;ins ++){
		
		cin >> n;
		n2 = n/2;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i = 0;i < n;i ++){
			cin >> a[i] >> b[i] >> c[i];	
		}
		dfs(0);
		//cout << an << " " << bn << " " << cn << endl;
		cout << endans << endl;
		secondans = endans = an = bn = cn = 0;
		memset(ans,0 ,sizeof(ans));
	}
	
	return 0;
}
//CCF,你的测试样例不行啊，都没换行符！！！  
/*
n
∑ a[i]
i=1 
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1
1 1 1

*/
