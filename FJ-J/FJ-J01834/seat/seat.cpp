#include <bits/stdc++.h>
using namespace std;

int n,m;
int nums[100]={};
int want;

int b(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>nums[i];
	}
	want=nums[0];
	sort(nums,nums+(n*m),b);
	int y=1;
	int count=0;
	for(int i=0;i<n*m;i++){
		count++;
		if(nums[i]==want)break;
	}
	while(count-n>0){
		count-=n;
		y++;
	}
	int x;
	if(y%2==0)x=n-count+1;
	else x=count;
	cout<<y<<' '<<x;
	return 0;
}
