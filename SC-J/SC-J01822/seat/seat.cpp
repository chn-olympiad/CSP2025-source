#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
struct node{
	int order;
	int grade;
}a[105];
bool cmp(node a,node b){
	return a.grade > b.grade; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i].grade;
		a[i].order = i;
	}
	sort(a+1,a+n*m+1,cmp);
	int pos;
	for(int i = 1;i <= n*m;i++){
		if(a[i].order == 1)pos = i;
	}
	
	int c = (pos-1)/n + 1;
	int r = 0;
	if(c %2 == 0)r = n - pos%n+1;
	else r = (pos-1)%n + 1;
	cout << c <<" "<<r;
	return 0;
}