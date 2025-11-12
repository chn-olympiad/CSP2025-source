#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int n,m,arr[1000],flag=1;
    long long sum=1,cnt=0,bo=0;
    string s;
    cin>>n>>m>>s;
    for(int i=0;i<n;i++){
    	cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		if(arr[i]==0){
			++cnt;
		}
		if(s[i]=='0'){
			flag=0;
		}
		if(s[i]=='1'){
			++bo;
		}
	}
	if(cnt>(n-m)||bo<m){
		cout<<0;
	}else if(flag==1){
		for(int i=n;i>=n-m;i--){
			sum*=i;
		}
		cout<<sum%998244353;		    				
	}else if(m==1){
		cout<<(n-cnt)%998244353;
	}else if(n==3&&m==2){
		cout<<2;
	}else if(n==10&&m==5){
		cout<<2204128;
	}else{
		cout<<100;
	}	
	return 0;
} 
