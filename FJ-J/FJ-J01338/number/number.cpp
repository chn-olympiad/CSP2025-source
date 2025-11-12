#include<bits/stdc++.h>
using namespace std;
bool cap(int a,int b){
	return a>b;
}
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	int n,sum=0,s[10005]={0};
	cin>>n;
	cout<<n;
	while(n!=0){
		if(n>=1000000){
			n-=n/1000000*1000000;
			s[1]=n/1000000;
			
		}else if(n>=100000){
			n-=n/100000*100000;
			s[2]=n/100000;
			
		}else if(n>=10000){
			n-=n/10000*10000;
			s[3]=n/10000;
			
		}else if(n>=1000){
			n-=n/1000*1000;
			s[4]=n/1000;
			
		}else if(n>=100){
			n-=n/100*100;
			s[5]=n/100;
			
		}else if(n>=10){
			n-=n/10*10;
			s[6]=n/10;
		
		}
		else if(n>=1){
			n-=n%10;
			s[7]=n%10;
			
		}
	}
//	sort(s+1,s+n+1,cap);
//	for(int i=1;i<=n;i++){
//		cout<<s[i];
//	}
	
	return 0;
} 
