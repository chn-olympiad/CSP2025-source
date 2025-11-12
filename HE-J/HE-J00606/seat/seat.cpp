#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	
	int s[n*m]={};
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	int a=s[0];
	sort(s,s+n*m);
	for(int i=0;i<n*m;i++){
		if(s[i]==a){
			k=n*m-i;
			break;
		}
	}
	int m1,n1;
	if(k%n==0){m1=k/n;
	}
	else{m1=k/n+1;
	}
	if(m1%2==1){n1=k%n;
	if(n1==0){n1=n;
	}
	}
	else{n1=n+1-k%n;
	if(n1==n+1){n1=n;
	}
	}
	cout<<m1<<' '<<n1;
	
	
	
	
	
	
	
	return 0;
}
