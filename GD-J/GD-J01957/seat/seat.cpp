#include<bits/stdc++.h>
using namespace std;
int a[105]={0};
int n,m,t,ind;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
	    cin>>a[i];
		if(i==0) t=a[0]; 
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==t) ind=i+1; 
	}
	if(ind%n==0){
		cout<<ind/n<<" ";
		if(ind/n%2==0){
			cout<<"1";
		}else{
			cout<<n;
		}
	} 
	else{
		cout<<ind/n+1<<" ";
		if((ind/n+1)%2==0){
			cout<<n-(ind%n-1);
		}else{
			cout<<ind%n;
		}
	}
	return 0;
} 

