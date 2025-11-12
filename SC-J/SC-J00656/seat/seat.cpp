#include<bits/stdc++.h>
using namespace std;
int n,m,h,j,now_,prev_;
int a[105];
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
	prev_=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1;
	while(a[i]!=prev_){
		i++;
	}
	now_=i;
	if(now_%n==0){
		j=now_/n;
	}else{
		j=now_/n+1;
	}
	if(j%2==1){
		if(now_%n==0){
			h=n;
		}else{
			h=now_%n;
		}
	}else{
		if(now_%n==0){
			h=1;
		}else{
			h=n-(now_%n)+1;
		}
	}
	cout<<j<<" "<<h;
	return 0;
} 