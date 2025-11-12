#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	long long h=a[1];
	sort(a+1,a+n*m+1);
	long long left=1;
	long long yo=n*m;
	long long pai=0;
    while(left<=yo){
    	long long mid=left+(yo-left)/2;
    	if(a[mid]==h){
    		pai=mid;
    		break;
		}else if(a[mid]<h){
			left=mid+1;
		}else{
			yo=mid-1;
		}
		 
	}
	pai=n*m-pai+1;


    if(pai<=n){
    	cout<<1<<" "<<pai;
	}else if(pai%n==0){
		if((pai/n)%2==0){
				cout<<pai/n<<" "<<1;
		}else{
			    cout<<pai/n<<" "<<n;
		}

	}else{long long l=pai%n;
	
		if((pai/n+1)%2==0){
		
			    cout<<pai/n+1<<" "<<n-l+1;
			    
		}else{
			cout<<pai/n+1<<" "<<l;
		}
	}
	
	return 0;
} 
