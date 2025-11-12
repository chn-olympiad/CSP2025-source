#include<bits/stdc++.h>
using namespace std;
bool cmp(int h,int k){
	return h>k;
}
int a[110],n,m,r,n1=1,m1=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			r=a[1];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(i%n==1){
		    m1++;
	    }
		else if(m1%2==1){
		    n1++;
	    }
		else{
		    n1--;
	    }
	    if(a[i]==r){
	    	cout<<m1<<" "<<n1;
	    	return 0;
		}
	}
	return 0;
}
