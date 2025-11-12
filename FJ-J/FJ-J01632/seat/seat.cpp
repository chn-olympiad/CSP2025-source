#include<bits/stdc++.h>
using namespace std;
struct student{
	int a;
	int o;
};
bool cmp(student a,student b){
	return a.a>b.a;
}
student a[120];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
//	preopen("input.in","r",stdin);
//	preopen("output.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].a;
		a[i].o=0;
	}
	a[1].o=1;
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i].o<<' ';
//	}
	for(int i=1;i<=m*n;i++){
		if(a[i].o==1){
			if(i%n==0){
				if((i/n)%2==1){
					cout<<i/n<<' '<<n;
				}else{
					cout<<i/n<<' '<<1;
				}
				//cout<<i<<' '<<j;
			}else{
				if((i/n+1)%2==1){
					cout<<i/n+1<<' '<<i%n;
				}else{
					cout<<i/n+1<<' '<<n-i%n+1;
				}
				//cout<<i<<' '<<m-j+1;
			}
		}
	}
	
	return 0;
}
