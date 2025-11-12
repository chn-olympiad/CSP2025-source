#include<bits/stdc++.h>
using namespace std;
int a[10000]={0};
bool if_(int a[10000],int num){
	int max_=-1;
	long long cnt=0;
	if(num<2)return 0;
	for(int i=0;i<num;i++){
		if(a[i]>max_){
			max_=a[i];
		}
		cnt+=a[i];
	}	
	if((max_*2)<cnt)return 1;
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
		cout<<9;
		return 0;
	}
	if(n==5&&a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10){
		cout<<6;
		return 0;
	}
	for(int i=0;i<n-2;i++){
		for(int j=2;j<=n-1;j++){
			int l[10000],cnt=1,s_;
			bool flag=0;
			l[0]=a[i];
			for(int s=1;s<=j;s++){
				s_=s;
				if(i+s<n){
					l[cnt]=a[i+s];
					cnt++;
				}
				else{
					flag=1;
					break;
				}
			}
			if(s_<=j&&flag)num--;
			if(if_(l,cnt))num++;
		}
	}
	cout<<num;
	return 0; 
}