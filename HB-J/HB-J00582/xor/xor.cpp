#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,a[500005],used[500005]={0},sl=0,sh=0,sc=0,gdl;
  cin>>n>>k;
  freopen("xor.in","r",stdin);
  for(int i=0;i<=n-1;i++){
  	cin>>a[i];
  	if(a[i]>a[i-1] && i!=0){
  		gdl=a[i-1];
  		a[i-1]=a[i];
  		a[i]=gdl;
  	}
  }
  for(int i=0;i<=n-1;i++){
  	if(a[i]==k){
  		sl++;
  		used[i]=1;
  	}
  }
  for(int i=0;i<=n;i++){
  	for(int j=i;j<=n;j++){
  		if(used[j]==1){
  			break;
  		}
  		else{
  			sh+=a[j];
  			if(sc==0){
  				sc=a[j];
  			}
  			else{
  				sc-=a[j];
  			}
  		}
  	}
  	if(sc==k || sh==k){
  		sl++;
  	}
  }
  cout<<sl;
  freopen("xor.out","w",stdout);
  return 0;
}
