#include <bits/stdc++.h>
using namespace std;
struct node{
	int id,num;
}b[110];
int n,m;
int a[11][11];
bool cmp(node a,node b){
	return a.num > b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> b[i].num;
		b[i].id = i;
	}
	sort(b+1,b+n*m+1,cmp);
	int i = 1,j = 1,cnt = 1;
	while(b[cnt].id != 1){
		if(i < n && j % 2) i++;
		else if(i == n && j % 2) j++;
		else if(i > 1 && !(j % 2)) i--;
		else if(i == 1 && !(j % 2)) j++;
		cnt++;
		cout << i << ' ' << j << "\n";
	}
	cout << j << ' ' << i;
	return 0;
}
