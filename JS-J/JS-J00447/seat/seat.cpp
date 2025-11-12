#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu{int a;bool isr;};
bool cmp(stu a,stu b){
	return a.a>b.a;}
stu a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].a;
		a[i].isr=(i==1);
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(!a[i].isr) continue;
		int c=i/n,r;
		if(i%n!=0) c++;
		if(c%2==1){
			if(i%n==0) r=n;
			else r=i%n;
		}else{
			if(i%n==0) r=1;
			else r=n-(i%n)+1;
		}
		cout<<c<<' '<<r;
		return 0;
	}
	return 0;
}
