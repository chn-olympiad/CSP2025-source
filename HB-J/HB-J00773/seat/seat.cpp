#include <bits/stdc++.h>
using namespace std;

struct Node{
	int id;
	int value;
}p[105],a[15][15];

bool cmp(Node a, Node b){
	return a.value>b.value;
}

int n,m;

int main(){
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int len = n*m;
	for(int i=1;i<=len;i++){
		cin >> p[i].value;
		p[i].id = i;
	}
	sort(p+1, p+1+len, cmp);//jiang xu pai xu
	int k=1;//zhi xiang p[k]
	for(int i=1;i<=m;i++){//an lie bian li
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[i][j].value = p[k].value;
				a[i][j].id = p[k].id;
				if(a[i][j].id == 1){ //found R
					cout << i << ' ' << j;
					return 0;
				}
				k++;
			}
		}else{
			for(int j=n;j>=1;j--){
				a[i][j].value = p[k].value;
				a[i][j].id = p[k].id;
				if(a[i][j].id == 1){ //found R
					cout << i << ' ' << j;
					return 0;
				}
				k++;
			}
		}
	}
	
	return 0;
}

