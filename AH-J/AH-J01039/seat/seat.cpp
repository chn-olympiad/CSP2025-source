#include<bits/stdc++.h>
using namespace std;

long long n,m,a[1000020];
bool cmp(int a,int b){
	return a>b;
}
int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long b=a[1],c=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			c=i;
			break;
		}
	}
	if(c<=n){
		cout<<1<<" ";
		if(c%n==0){
			cout<<n;
		}else{
			cout<<c%n;
		}
	}else{
		if(c%n==0){
			cout<<c/n<<" "<<n;
		}else{
			if((c/n+1)%2==0){
			    cout<<c/n+1<<" "<<abs(c%n-n-1);	
			}else{
				cout<<c/n+1<<" "<<c%n;
			}
		}
	}

    return 0;
}
