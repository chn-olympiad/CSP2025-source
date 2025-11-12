#include<bits/stdc++.h>
using namespace std;
fstream("seat.in","r",stdin);
fstream("seat.out","w",stdout);
struct stu{
	int a,b,c;
};
bool Cmp1(stu a,stu b){
	return a.a>b.a;
}
bool Cmp2(stu a,stu b){
	return a.b>b.b;
}
stu l[105];
int main(){
	int m,n;
	cin>>n>>m;
	for(int i = 1;i<=m*n;i++){
		cin>>l[i].a;
		l[i].b=i;
	}
	sort(l+1,l+m*n+1,Cmp1);
	for(int i = 1;i<=m*n;i++){
		l[i].c=i;
	}
	sort(l+1,l+m*n+1,Cmp2);
	int x,y,s=l[1].c;
	y=s/m+1;x=s%m;
	if(y%2==0){
		x=n-x;
	}
	cout<<x<<' '<<y;
	return 0;
}
