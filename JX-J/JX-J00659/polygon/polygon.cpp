#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+5],sun=0,max=0,xz=0,cz=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
       sun+=a[i];
       max=a[i];
       cz+=1;
       for(int j=1;j<=n;j++){
          if(a[j]!=a[i]){
          sun+=a[j];
          }
          if(a[j]>max){
            max=a[j];
          }
          cz+=1;
            for(int g=1;g<=n;g++){
               if(a[g]!=a[i] && a[g]!=a[j]){
                 sun+=a[g];
                 if(a[g]>max){
                    max=a[g];
                 }
                 cz+=1;
                 }
                 if(sun>2*max){
                   xz+=1;
                 }else{
                   if(cz<n){
                     for(int h=1;h<=n;h++){
                        if(a[h]!=a[i] && a[h]!=a[j] && a[h]!=a[g]){
                          sun+=a[h];
                          if(a[h]>max){
                            max=a[h];
                          }
                        }
                          if(sun>2*max){
                            xz+=1;
                          }else{
							   if(cz<n){
								 for(int l=1;l<=n;l++){
									if(a[l]!=a[i] && a[l]!=a[j] && a[l]!=a[g] && a[l]!=a[h]){
									  sun+=a[l];
									  if(a[l]>max){
										max=a[l];
									  }
									}
									  if(sun>2*max){
										xz+=1;
							          }
							     }
							   }
						  }
				     }
				   }
				  }
		   }
    }
    cout<<xz;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
