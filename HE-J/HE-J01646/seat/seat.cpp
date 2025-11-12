#include<bits/stdc++.h>
using namespace std;
int a[200],n,m,c=1,r;
bool cmp(int a1,int b){
	return a1>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	bool f=1;
	for(int i=1;i<=n*m;i++){
		if(f)r++;
		else r--;
		if((i-1)%n==0&&i!=1){
			if(f){
				c++;
				r=n;				
			}else{
				c++;
				r=1;
			}
			f=!f;
		}
		if(k==a[i]){
			cout<<c<<" "<<r;
			return 0; 
		} 
	}
	return 0;
}

