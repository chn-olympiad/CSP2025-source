#include<bits/stdc++.h>
using namespace std;
const int N=10;
int a[N*N];
int ans1,ans2;
#define ll long long  
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
	    cin>>a[i];
	}
	int sum=a[1],r=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
	    if(sum!=a[i]){
			r++;
		}else{
		    break;
		}
	}
	ans1=r/n+1;
	r-=(r/n)*n;
	cout<<ans1<<" ";
	if(ans1%2==1){
		if(r==0){
			cout<<"1\n";
		}else{
	        cout<<r<<"\n";
	    }
	}else{
		if(n-r==0){
		    cout<<n<<"\n";
		}else{
		    cout<<n-r<<"\n";
	    }  
	}
    return 0;
}
