#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;	
ll l,h;
ll num[500005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ll nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>num[i];
	}	
	ll x=num[1],x_i;
	sort(num+1,num+1+nm,cmp);
	for(int i=1;i<=nm;i++){
		if(num[i]==x){
			x_i=i;
			break;
		}
	}
//cout<<l<<endl;
	if(x_i%n==0) l=x_i/n;
	else l=x_i/n+1;
//		cout<<h<<endl;
	if(l%2==0) h=n-x_i%n+1;
	else h=x_i%n;
	if(h==0) h=n;

	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
