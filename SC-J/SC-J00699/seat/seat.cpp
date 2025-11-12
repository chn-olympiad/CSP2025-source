#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10005;
int n,m,a[N];
struct Stu{
	int num,grade;
}stu[N];
bool cmp(Stu x,Stu y){
	return x.grade>y.grade;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++){
		stu[i].num=i;
		scanf("%lld",&stu[i].grade);
	}
	sort(stu+1,stu+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(stu[i].num==1){
			int h=i%n,l=i/n;
			if(i%n){
				l++;
			}
			if(h==0)h=n;
			printf("%lld %lld",l,h);
		}
	}
	return 0;
}
// 3 3
//94 95 96 97 98 99 100 93 92