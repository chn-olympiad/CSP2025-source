#include<bits/stdc++.h>
using namespace std;
struct stu{
	int grade,index;
}a[100];
bool cmp(stu a,stu b){
	return a.grade>b.grade;
}
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	int n,m,cnt;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].grade;
		a[i].index=i;
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<m*n;i++){
		if(a[i].index==0){
			cnt=i+1;
			break;
		}
	}
	int c=ceil(1.0*cnt/n),r;
	if(c%2){
		r=cnt-(c-1)*n;
	}else{
		r=c*n-cnt+1;
	}
	printf("%d %d",c,r);
	return 0;
}
