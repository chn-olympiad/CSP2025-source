#include <bits/stdc++.h>
using namespace std;
struct stu{
	int c;
	int z;
	int hang;
	int lie;
	
}a[105];
bool cmp(stu x,stu y){
	if(x.c>y.c) return x.c>y.c;
	if(y.c>x.c) return x.c<y.c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].c;
		if(i!=1){
			a[i].z=0;
	}
	}
	a[1].z=1;
	sort(a+1,a+n+1,cmp);
	int ans=0;
	int x=0;
	for(int i=1;i<=n*m;i++){
		if(i%n==0&&i!=1){
			ans=0;
			x=i/n+1;
			if(x%2==0){
				ans=1;
				a[i].hang=n;
				a[i].lie=x-1;
			}else if(x%2==1){
				ans=2;
				a[i].hang=1;
				a[i].lie=x-1;
			}
			cout<<x<<endl;
		}else if(i%n!=0&&i!=1){
		if(ans==1){
			int y=i%n-1;
			a[i].hang=n-y;
			a[i].lie=a[i-i%n].lie+1;
			
		}else if(ans==2){
			int y=i%n-1;
			a[i].hang=1+y;
			a[i].lie=a[i-i%n].lie+1;
			
		}
	}else if(i==1){
		x=1;
		ans=2;
		a[i].hang=1;
		a[i].lie=1;
	}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].z==1){
			cout<<a[i].lie<<" "<<a[i].hang;
			
		}
	}
//	cout<<1;
}
