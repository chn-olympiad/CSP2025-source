#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool biao[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n;
	cin>>k;
	int d=0;
	int sum=0;
	int p=0;
	
    for(int i=1;i<=n;i++) {
	cin>>a[i];
	if(a[i]==1&&a[i-1]==1&&!biao[i-1]){
		d++;
		biao[i];
	}
	if(a[i]==k){
		sum++;
	}
	else if(a[i]==1){
		p++;
	}
}
   if(n<3) cout<<0;
   else if(k==0){
   	if(p==n) cout<<n/2;
   	else cout<<sum+d;
   }
   else if(k==1) cout<<sum;    
   fclose(stdin);
   fclose(stdout);
   return 0;
}
	
