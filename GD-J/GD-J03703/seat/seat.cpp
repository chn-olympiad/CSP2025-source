#include "bits/stdc++.h"
using namespace std;
int n,m;
struct stu{
	int m;
	int id;
}a[110];
bool cmp(stu a,stu b){
	return b.m < a.m;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i].m;
		if(i==1){
			a[i].id = 0;
		}
		else{
			a[i].id = 1;
		}
	}
	sort(a+1,a+n*m+1,cmp);
	int t=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==0){
			t = i;
			break;
		}
	}
	int x=0,y=0;
	if(t%n==0)
	{
		x = (t/n);
	}
	else{
		x = (t/n)+1;
	}
	if(x%2==0){
		int temp = t-((x-1)*n);
		y = n-temp+1;
	}
	else {
		int temp = t-((x-1)*n);
		y = temp; 
	}
	cout << x << " " << y;
	return 0;
}
