#include<bits/stdc++.h>
using namespace std;
struct node{
	int t;
	bool b = false;
};
node a[105];
int cmp(node s,node s1){
	if(s.t>s1.t){
		return 1;
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	a[1].b = true;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i].t;
	}
	sort(a+1,a+n*m+1,cmp);
	int number;
	for(int i = 1;i<=n*m;i++){
		if(a[i].b){
			number = i;
			break;
		}
	}
	int sum,sum1;
	if(number % n == 0){
		sum = number/n;
	}else{
		sum = number/n+1;
	}
	sum1 = number - n * (sum - 1);
	if(sum % 2 == 0){
		sum1 = n + 1 - sum1;
		if(sum1 == 0){
			sum1 = 1;
		}
	}
	cout<<sum<<' '<<sum1;
}
