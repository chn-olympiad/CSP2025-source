#include<bits/stdc++.h>
using namespace std;
struct stu{
	int num;
	int n;
	int m;
}a[101];
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,b[101],x=1,y=1,ds=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	t=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		a[i].num=b[i];
	}
	for(int i=1;i<=n*m;i++){
		a[i].n=x;
		a[i].m=y;
		if(i%n==0){
			x++;
		}else if(ds%2==1){
			y++;
		}else{
			y--;
		}
		if(i%n==0){
			ds++;
		}	
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].num==t){
			cout<<a[i].n<<" "<<a[i].m;
			break;
		}
	}
	return 0;
}
