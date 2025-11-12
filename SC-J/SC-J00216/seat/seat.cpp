#include<bits/stdc++.h>
using namespace std;
int n,m,sum,x=1,y=1;
struct St{
	int v;
	bool f;
} a[1010];
bool cmp(St a,St b){
	return a.v>b.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	sum = n*m;
	for(int i=1;i<=sum;i++){
		cin >> a[i].v;
		if(i == 1) a[i].f = 1;
		else a[i].f = 0;
	}
	sort(a+1,a+sum+1,cmp);
	if(a[1].f){
		cout << "1 1";
		return 0;
	}
	int pos=2,x=1,y=1;
	bool flag=0;
	while(pos <= sum){
		if(!flag && x<n) x++;
		else if(!flag){
			y++;
			flag = 1;
		}
		else if(x > 1) x--;
		else{
			y++;
			flag = 0;
		}
		if(a[pos].f){
			cout << y << ' ' << x;
			break;
		}
		pos++;
	}
	return 0;
}