#include<bits/stdc++.h>
using namespace std;
long long n,m,c=1,r=1,sum,ans,p=1;
int a[150];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	int o=n*m;
	sort(a+1,a+o+1,cmp); 
	for(int i=1;i<=o;i++){
		if(a[i]==sum){
			ans=i;
			break;
		}
	}
	for(int i=1;i<=o;i++){
		while(ans-m>0){
			ans-=m;
			c++;
		}
		if(c%2!=0){
			r=ans;
		}else{
			r=n-ans+1;
		}
	}
	cout<<c<<" "<<r;
}
