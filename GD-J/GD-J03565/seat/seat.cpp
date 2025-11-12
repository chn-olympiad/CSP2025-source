#include<bits/stdc++.h>
using namespace std;
string s,s1;
struct cc{
	long long x,id;
}a[100101];
long long ans,n,m,x,num;
bool cmp(cc x,cc y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].x,a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			x=i;
			break;
		}
	}
	num=x/n;
	if(x%n!=0){
		num++;
		x%=n;
	} 
	else x=n;
	if(num%2==0) cout<<num<<" "<<n-x+1;
	else cout<<num<<" "<<x;
}
