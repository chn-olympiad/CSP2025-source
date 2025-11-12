#include<bits/stdc++.h> 
using namespace std;
int n,m;
struct stu{
	int num,g;
}a[105];
bool cmp(stu a,stu b){
	return a.g>b.g;
}
void turn(int p){
	int s=(p+n-1)/n,k=0;
	if(s%2)k=(p-1)%n+1;
	else k=(n-((p-1)%n));
	cout<<s<<' '<<k;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].g;
		a[i].num=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			turn(i);
			return 0;
		}
	}
	return 0;
}
