#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,s,ans2;
double ans1;
struct node{
	int no;
	int sc;
}a[110]; 
bool cmp(node x,node y){
	return x.sc>y.sc;
}
int quzheng(int v,int w){
	int z=v/w;
	if(z*w!=v){
		z++;
	}
	return z;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	a[1].no=1;
	int r=m*n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sc;
	}
	sort(a+1,a+1+r,cmp);
//	for(int i=1;i<=n*m;i++) cout<<a[i].sc<<endl;
	for(int i=1;i<=n*m;i++){
		if(a[i].no==1){
			s=i;
			break;
		}
	}
//	cout<<s<<endl;
	int t=quzheng(s,n); 
	if(t%2==0){
		ans1=t;
		ans2=n-s%n+1;
		cout<<ans1<<' '<<ans2;
	}else{
		ans1=t;
		ans2=s%n;
		if(ans2==0)ans2=n;
		cout<<ans1<<' '<<ans2;
	} 
	return 0;
}

