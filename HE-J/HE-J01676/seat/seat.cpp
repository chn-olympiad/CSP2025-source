#include<bits/stdc++.h> 
using namespace std;
int a[105];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,c=-100000,sum=0,e=1,u=0,d=100000;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]<d)
		  d=a[i];
		if(a[i]>c)
		  c=a[i];
	}
	sum=a[1];
	if(sum==d){
		cout<<n<<" "<<m;
		return 0;
	}
    if(sum==c||(n==1&&m==1)){
    	cout<<1<<" "<<1;
    	return 0;
	}
    for(int i=n*m;i>=1;i--){
    	for(int y=1;y<=n*m;y++){
    		if(a[i]>a[i-1]){
    			a[i]=a[i-1];
			}
		}
	}
	for(;e<=n*m;e++){
		if(a[e]==sum){
			break;
		}
	}
	cout<<e<<" ";
	if(e==m){
		cout<<m-(e%m)-1<<" "<<n-(e%n);
	}else
	  cout<<m-(e%m)<<" "<<n-(e%n);
	return 0;
}
