#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
void d(int p,int b,int maxn,int ch){
	if(p>n){
		if(b>=3&&ch>maxn*2){
			ans++;
		}
		return ;
	}
	d(p+1,b+1,max(maxn,a[p]),ch+a[p]);
	d(p+1,b,maxn,ch);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
      cin>>n;
      for(int i=1;i<=n;i++){
      	  cin>>a[i]; 
	  }
	  d(1,0,0,0);
	  cout<<ans;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
