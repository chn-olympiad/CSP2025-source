#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[500005];
int cnt=0;
long long sam=0,san=0;
long long get_num(long long a[],long long l,long long r){
	long long ans=0;
	for(int i=l;i<=r;i++){
		ans+=a[i]^ans;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	long long leftt=1,rightt=n;
    for(int i=1;i<=n;i++){
    	sam=0;
    	for(int j=1;j<=n;j++){
		    while(leftt<=rightt){
		    	if(i==j&&(leftt!=rightt)){
			        sam=a[i];
					san=get_num(a,leftt,rightt); 	     
			    }else if(i!=j||((i<=leftt&&j>rightt)||(i>=rightt)||(j<=leftt)||(i<leftt&&j>=rightt))){
			    	sam=get_num(a,i,j);
			    	san=get_num(a,leftt,rightt); 
				}
				if(sam==k&&san==k){
					cnt++;
				}  
			     rightt--;
		    }
		    leftt++;
		} 
	}
	cout<<cnt;
	return 0;
} 
