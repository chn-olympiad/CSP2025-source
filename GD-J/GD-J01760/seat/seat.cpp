#include <iostream>
#include <algorithm>
using namespace std;
int a[101][101];
int b[501];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> b[i];
	}
	int ming = b[1];
	sort(b+1,b+(n*m)+1);
	int cnt = n*m;
	for(int i=1;i<=n;i++){
		if(i % 2==1){
			for(int j=1;j<=m;j++){
				a[i][j] = b[cnt];
				cnt--;
			}
		}else{
			for(int j=m;j>=1;j--){
				a[i][j] = b[cnt];
				cnt--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j] == ming){
				cout << i << ' ' << j;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
