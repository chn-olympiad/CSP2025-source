#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],x,tc,tp;
bool cmp(int i,int j){
	return i>j;
	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	tc=a[1];
	sort(a+1,a+x+1,cmp);
	for(int i=1;i<=x;i++){
		if(a[i]==tc){
			tp=i;
			break;
		}
	}
    if(tp==1){
    	cout<<1<<' '<<1;
    	return 0;
	}
	if(tp==x){
		if(m%2==0){
			cout<<m<<' '<<1;
		}
		else{
			cout<<m<<' '<<n;
		}
		return 0;
	}
	if(tp%n==0){
		int h=tp/n;
		if(h%2==0){
			cout<<h<<' '<<1;
		}
		else{
			cout<<h<<' '<<n;
		}
		return 0;
	}
	if(tp%n!=0){
		int x=tp/n+1,y=tp%n;
		if(x%2==0){
			y=n-y+1;
		}
		cout<<x<<' '<<y;
		return 0;
	}
	return 0;
}
