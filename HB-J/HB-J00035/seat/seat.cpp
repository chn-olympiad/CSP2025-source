#include<bits/stdc++.h>
using namespace std;
int m,n,r,x,y;
struct node{
	int num,isr;
};
node a[1000000];
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	a[1].isr=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
	}
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].isr==1){
			r=i;
			//cout<<a[i].num<<endl;
		}
	}
	//cout<<r<<endl;
	int s=ceil(r*1.00/n);
	//cout<<s<<endl;
	if(s%2==0){
		x=s;
		y=s*n-(r-1);
		//cout<<s<<' '<<n<<' '<<r<<endl;
		//cout<<x<<' '<<y;
		
	}else{
		x=s;
		y=r+n-s*n;
		//cout<<s<<' '<<n<<' '<<r<<endl;
	}
	cout<<x<<' '<<y;
	return 0;
}
