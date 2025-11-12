#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,a[10000000],c=1,r=1,p,d=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	p=a[1];
	sort(a,a+n*m+1);
	for(int i=n*m;i>=1;i--){
    	if(r>n||r==0){
    		c++;
    		if((n*m-i+1)/n%2==0){
    			r=1;
    			d=1;
//    			cout<<c<<r;
//    			cout<<(n*m-i+1)/n<<" ";
			}else{
				r=n;
				d=0;
//				cout<<c<<r;
//				cout<<(n*m-i+1)/n<<" ";
			}
		}
		if(a[i]==p){
			cout<<c<<" "<<r;
			break;
		}
//		cout<<c<<" "<<r<<" "<<d<<"   ";
		if(d==1){
			r++;
		}else if(d==0){
			r--;
		}
	
	}
	return 0;
}
