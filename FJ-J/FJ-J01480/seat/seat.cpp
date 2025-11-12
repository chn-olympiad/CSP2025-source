#include<bits/stdc++.h>
using namespace std;
string s;
struct node{
	int id,s;
}a[100005];
int cnt,f,n,m,v;
bool cmp(node x,node y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
	//	cout<<a[i].s<<" ";
		if(a[i].id==1){
			f=i;
		}
	}
	if(f%n==0){
		v=f/n;
	}else{
		v=f/n+1;
	}
	if(v%2==0){
		cout<<v<<" "<<m-f%n<<endl;
	}else{
		cout<<v<<" "<<(f-1)%n+1<<endl;
	}
	return 0;
}
