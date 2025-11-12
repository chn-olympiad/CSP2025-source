#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[100001];
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n*m;i++){
	    cin>>a[i];	
	}
	int x=a[1],ans,s;
	sort(a+1,a+m*n+1);
	for(int i=1;i<=n*m;i++){
	  if(a[i]==x){
		  ans=m*n-i+1;
		  int c=ans%n;
		  if(c==0) s=(ans/n);
		  else s=ans/n+1;
		  cout<<s<<" ";
		  if(s%2==0&&c!=0)cout<<n-c+1;
		  if(s%2==0&&c==0)cout<<1;
		  if(c==0&&s%2==1)cout<<n;
		  if(s%2==1&&c!=0) cout<<c;
	    } 	
	}
    return 0;
}
