#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int b[111];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>b[i];
	}
	int r=b[1];
	int num;
	sort(b+1,b+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		if(r==b[i]){
			num=i;
			break;
		}
	}
	bool flag=true;
	int rn=0,rm=0; 
	if(num%n==0){
		rm=num/n;
	}
	else{
		rm=num/n+1; 
	}
	if(rm%2==0){
		flag=false;
	}
	else{
		flag=true;
	}
	if(flag){
		if(num%n==0){
			rn=n;
		}
		else{
			rn=num%n;
		}	
	}
	else{
		if(num%n==0){
			rn=1; 
		}
		else{
			rn=n-num%n+1;
		}
	}
	cout<<rm<<" "<<rn;
	return 0;
}
