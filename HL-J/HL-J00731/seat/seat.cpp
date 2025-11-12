#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n = 0;
	int m = 0;
	int n2 = 1;
	int m2 = 1;
	bool flag2 = false;
	bool flag = true;
	int a[22] = {0};
	cin >> n >> m;
	for(int i = 0;i < n*m;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+m,cmp);
	for(int i = 1;i < n*m;i++){
		if(a[0] > a[i]){
			cout << n2 << " " << m2;
			break;
		}
		if(a[0] < a[i]){
			flag2 = false;
			if(m2 == 1 && !flag){
				n2++;
				flag2 = true;
				flag = true;
			}
			else if(m2 <= m && !flag && m2 > 1){
				m2--;
			}
			else if(m2 >= 1 && flag && m2 < m){
				m2++;
			}
			else if(m2 == m && flag){
				n2++;
				flag2 = true;
				flag = false;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
