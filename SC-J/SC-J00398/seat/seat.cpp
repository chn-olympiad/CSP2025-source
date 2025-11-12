#include<bits/stdc++.h>
using namespace std;
struct stu{
	int grade;
	int num;
}a[200];
int n,m;
bool cmp(stu x,stu y){
	return x.grade>y.grade;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].grade;
		a[i].num=i;
	}
	sort(a+1,a+1+m*n,cmp);
	int q;
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			if(i%n==0){
				q=i/n;
				cout<<q<<' ';
			}else{
				q=i/n+1;
				cout<<q<<' ';
			}
			if(q%2==0){
				if(i%n==0){
					cout<<n;
				}else{
					cout<<n-i%n+1;
				}
				break;
			}else{
				if(i%n==0){
					cout<<n;
				}else{
					cout<<i%n;
				}
				break;
			}
		}
	}
}