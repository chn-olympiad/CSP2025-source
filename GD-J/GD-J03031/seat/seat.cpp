#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu{
	int num;
	int s;
	int grade;
};
stu a[100];
bool cmp(stu t1,stu t2){
	return t1.grade > t2.grade;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i ++){
		cin >> a[i].grade;
		a[i].num = i;
	}
	sort(a+1,a+1+n*m,cmp);
	int k;
	for(int i = 1; i <= n*m; i++){
		if(a[i].num == 1){
			k = i;
			break;
		}
	}
	int lie;
	if(k <= n) lie = 1;
	else lie = k / n + 1; 
	int ko = 1;
	for(int i = 1; i <= k ; i++){
		if(ko == n && (i / n) % 2 == 1 ){
			ko = n;
			continue;
		}
		if(ko == 1&& (i / n) % 2 == 0){
			ko = 1;
			continue;
		}
		if((i / n) % 2 == 1 ) ko++;
		if((i / n) % 2 == 0) ko--;
	}
	cout << lie << " " << ko;
	return 0;
}
