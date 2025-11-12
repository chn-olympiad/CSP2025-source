#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu{
	int num,c,r,ans;
}a[110];
bool cnt(stu x,stu y){
	return x.ans>y.ans;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=0;
	for(int i=1;i<=m;i++){
		if(i%2==1)
			for(int j=1;j<=n;j++){
				cin>>a[++len].ans;
				a[len].num=len;;
			}
		else if(i%2==0)
			for(int j=n;j>=1;j--){
				cin>>a[++len].ans;
				a[len].num=len;
			}
	}
	sort(a+1,a+len+1,cnt);
	len=0;
	for(int i=1;i<=m;i++){
		if(i%2==1)
			for(int j=1;j<=n;j++){
				a[++len].c=i;a[len].r=j;
			}
		else if(i%2==0)
			for(int j=n;j>=1;j--){
				a[++len].c=i;a[len].r=j;
			}
	}
	for(int i=1;i<=len;i++)
		if(a[i].num==1){
			cout<<a[i].c<<' '<<a[i].r;
			return 0; 
		} 
	return 0;
}
