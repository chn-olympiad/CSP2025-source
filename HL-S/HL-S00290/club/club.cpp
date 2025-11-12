#include<bits/stdc++.h>
using namespace std;
long long n;
long long aa=0,bb=0,cc=0;
long long ans=0;
long long t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
	  cin>>a[i].a1>>a[i].a2>>a[i].a3;
}   
    if(n==1){
    	if(a[0].a1>a[0].a2&&a[0].a1>a[0].a3)
            ans+=a[0].a1;
        else if(a[0].a2>a[0].a1&&a[0].a2>a[0].a3)
            ans+=a[0].a2;
        else if(a[0].a3>a[0].a2&&a[0].a3>a[0].a1)
            ans+=a[0].a3;
	}
    if(n==2)
      if(a[0].a1>a[0].a2&&a[0].a1>a[0].a3){
          if(a[1].a2>=a[1].a3)
            ans+=a[0].a1+a[1].a2;
          else if(a[1].a3>=a[1].a2)
            ans+=a[0].a1+a[1].a3;
      } 
	  
	  
	  else if(a[0].a2>a[0].a1&&a[0].a2>a[0].a3){
          if(a[1].a1>=a[1].a3)
            ans+=a[0].a2+a[1].a1;
          else if(a[1].a3>=a[1].a1)
            ans+=a[0].a2+a[1].a3;
      } 
	  
	  
	  else if(a[0].a3>a[0].a2&&a[0].a3>a[0].a1){
          if(a[1].a1>=a[1].a2)
            ans+=a[0].a3+a[1].a1;
          else if(a[1].a2>=a[1].a1)
            ans+=a[0].a3+a[1].a2;}
            
      else if(a[0].a1==a[0].a2&&a[0].a1>a[0].a3){
          if(a[1].a1>=a[1].a2&&a[1].a1>=a[1].a3)
            ans+=a[0].a2+a[1].a1;
          else if(a[1].a2>=a[1].a1&&a[1].a2>=a[1].a3)
            ans+=a[0].a1+a[1].a2;
          else if(a[1].a3>=a[1].a1&&a[1].a3>=a[1].a2)
            ans+=a[0].a2+a[1].a3;
      }   
	  else if(a[0].a1==a[0].a2&&a[0].a1<a[0].a3){
          if(a[1].a1>=a[1].a2)
            ans+=a[0].a3+a[1].a1;
          else if(a[1].a2>=a[1].a1)
            ans+=a[0].a3+a[1].a2;}  
      else if(a[0].a1==a[0].a3&&a[0].a1>a[0].a2){
          if(a[1].a1>=a[1].a2&&a[1].a1>=a[1].a3)
            ans+=a[0].a3+a[1].a1;
          else if(a[1].a2>=a[1].a1&&a[1].a2>=a[1].a3)
            ans+=a[0].a3+a[1].a2;
          else if(a[1].a3>=a[1].a1&&a[1].a3>=a[1].a2)
            ans+=a[0].a1+a[1].a3;
      }   
	  else if(a[0].a1==a[0].a3&&a[0].a1<a[0].a2){
          if(a[1].a1>=a[1].a3)
            ans+=a[0].a2+a[1].a1;
          else if(a[1].a3>=a[1].a1)
            ans+=a[0].a2+a[1].a3;}  
      else if(a[0].a2==a[0].a3&&a[0].a2>a[0].a1){
          if(a[1].a1>=a[1].a2&&a[1].a1>=a[1].a3)
            ans+=a[0].a2+a[1].a1;
          else if(a[1].a2>=a[1].a1&&a[1].a2>=a[1].a3)
            ans+=a[0].a3+a[1].a2;
          else if(a[1].a3>=a[1].a1&&a[1].a3>=a[1].a2)
            ans+=a[0].a2+a[1].a3;
      }   
	  else if(a[0].a2==a[0].a3&&a[0].a2<a[0].a1){
          if(a[1].a2>=a[1].a3)
            ans+=a[0].a3+a[1].a2;
          else if(a[1].a3>=a[1].a2)
            ans+=a[0].a2+a[1].a3;}  
      else if(a[0].a1==a[0].a3&&a[0].a1==a[0].a2){
          if(a[1].a1>=a[1].a2&&a[1].a1>=a[1].a3)
            ans+=a[0].a3+a[1].a1;
          else if(a[1].a2>=a[1].a1&&a[1].a2>=a[1].a3)
            ans+=a[0].a3+a[1].a2;
          else if(a[1].a3>=a[1].a1&&a[1].a3>=a[1].a2)
            ans+=a[0].a1+a[1].a3;}   
        cout<<ans<<endl;  }
	return 0;
}
