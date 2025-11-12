#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt;
int c,r;
struct Student{
	int point,num;
}a[110];
bool cmp(Student a,Student b){
	return a.point>b.point;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt = n*m;
	for(int i = 1;i<=cnt;i++){
		cin>>a[i].point;
		a[i].num = i;
	}
	sort(a+1,a+cnt+1,cmp);
	int u = 0;
	for(int i = 1;i<=cnt;i++){
		if(a[i].num==1){
			u = i;
		}
	}
	c = u/n;
	if(u%n!=0){
		c+=1;
	}
	u%=n;
	if(c%2==1){
		if(u==0){
			r = n;
		}
		else{
			r = u;
		}
	}
	else{
		if(u==0){
			r = 1;
		}
		else{
			r = n-u+1;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
