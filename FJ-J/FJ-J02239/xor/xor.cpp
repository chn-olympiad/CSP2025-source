#include<bits/stdc++.h>
using namespace std;
int a,n,k[500005],ans,b=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>n;
	for(int i=1;i<=a;i++){
		cin>>k[i];
		if(k[i]==0)b++;
	}
	if(n==0){	
	if(b!=0)ans=b+(a-b)/2;
	else if(a%2==0)ans=a/2;
	}
	else if(n==1){
		ans=a-b+b/3;
		
	}
	cout<<ans;//音氏。。。 
	return 0;
}
