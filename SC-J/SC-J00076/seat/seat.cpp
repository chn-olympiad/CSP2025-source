#include<bits/stdc++.h>
using namespace std;
long long n,m,r,rx,ry;
long long a[110];
bool cmp(long long a1,long long a2){
	return a1>a2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    bool flag=0;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
    	if(i==1){
    		r=a[i];
		}
		if(a[i]>=a[i-1]){
			flag=1;
		}
	}
	if(flag==0){
		cout<<n*m;
		return 0;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
    	if(r==a[i]){
			ry=i/n;
		}
	}
	if(ry%2==1){
		sort(a+ry*m-1,a+r,cmp);
		for(int i=ry*m-1;i<=r;i++){
		    if(a[i]==r){
		    	rx=i;
			}
	    }
	}
	else{
		sort(a+ry*m-1,a+r);
		for(int i=ry*m-1;i<=r;i++){
		    if(a[i]==r){
		    	rx=i;
			}
	    }
	}
	cout<<ry<<" "<<rx;
	return 0;
}
//2 2
//99 100 97 98