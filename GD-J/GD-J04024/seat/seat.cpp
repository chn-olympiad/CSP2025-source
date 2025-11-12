#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int num[N*N];
int n,m;
int p,goal;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			++p;
			cin >> num[p];
		}
	}goal = num[1];
	sort(num+1,num+1+p,cmp);
	int ans;
	int x=1,y=1;
	if(num[1]==goal){
		cout << "1 1";
		return 0;
	}
	for(int i=2;i<=p;i++){
		if(y%2==1){
				x++;
				if(x==n+1) x = n, y++;
			}
			else{
				x--;
				if(x==0) x = 1, y++;
			}
		if(num[i]==goal){
			cout << y << " " << x;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
