#include <bits/stdc++.h>
using namespace std;
int cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c=1,r=0;
	int n,m;
	cin>>n>>m;
	const int N=n*m;
	int a[N+5];
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+N+1,cmp);
	//cout<<a[1]<<a[2]<<a[3]<<a[4];
	for(int i=1;i<=N;i++){
		
		r++;
		if(r==n+1){
			c++;
			r=1;
		}
		if(a[i]==R){
			break;
		}		
	}
	if(c%2==0){
		cout<<c<<" "<<r;
	}else{
		cout<<c<<" "<<n-r+1;
	}
	/*
	if(new_r%2==0){
		if(new_r%n==0 && new_r%m==0){
			cout<<new_r/n<<" "<<new_r/m<<endl;
		}else if(new_r%n==0){
			cout<<new_r/n<<" "<<new_r/m+1<<endl;
		}else if(new_r%m==0){
			cout<<new_r/n<<" "<<new_r/m<<endl;
		}else{
			cout<<new_r/n+1<<" "<<new_r/m+1<<endl;
		}
	}else{
		if(new_r%n==0){		
	    	cout<<new_r/n<<" "<<n-new_r%n<<endl;
		}else{
			cout<<new_r/n+1<<" "<<n-new_r%n<<endl;
		}
	}
	*/
	return 0;
}
