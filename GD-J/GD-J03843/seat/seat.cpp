#include<bits/stdc++.h>
using namespace std;
bool cmp(int e,int f){
	return e>f;
}
int n,m,c,r,cnt,b;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	b=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			cnt=i+1;
		}
	}
	if(cnt%n==0){
		c=cnt/n;
	}
	else{
		c=cnt/n+1;
	} 
	if(c%2!=0){
		if(cnt%n==0){
			r=n;
		}else{
			r=cnt%n;
		}
	}else{
		if(cnt%n==0){
			r=1;
		}else{
			r=n+1-cnt%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
