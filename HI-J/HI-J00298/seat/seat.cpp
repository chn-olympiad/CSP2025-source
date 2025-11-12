#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
	int l=0,h=0,cnt=0,sum=0;
	cin>>l>>h;
	for(int i=1;i<=l*h;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+l*h+1,cmp);
	for(int i=1;i<=l*h;i++){
		if(cnt==a[i])sum=i;
	}
	if(sum<h&&sum<l)cout<<sum/l+1<<" "<<sum%l;
	else if(sum==l*h)cout<<l<<" "<<h;
	else if((sum%l)%2==0&&sum%l!=0)cout<<sum/l<<" "<<l-sum%l;
	else if(sum%l%2==0)cout<<sum/l<<" "<<1;
	else if(sum%l!=0&&(sum-1)%l==0)cout<<sum/l+1<<" "<<sum%l;
	else if(sum%l!=0)cout<<sum%l<<" "<<sum%l-1<<8;
	
	return 0;
}

