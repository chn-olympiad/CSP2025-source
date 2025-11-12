#include<bits/stdc++.h>
using namespace std;
int n,m,a[150];
int gr;
int main(){
    freopen("seat2.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    gr=1;
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
        //cout<<"a[i]:"<<a[i]<<endl;
        if(a[i]>a[1]&&i!=1){
                //cout<<a[i]<<endl;
            gr++;
        }
    }
    //cout<<a[1]<<endl;
    //cout<<gr<<endl;
    if(gr%n==0) printf("%d ",gr/n);
    else printf("%d ",gr/n+1);
    if(gr%(2*n)==0) printf("1 *1");
    else{
        if(gr%(2*n)>n) printf("%d",n-gr%n);
        else if(gr%n==0){
			if(gr/n%2==1) printf("%d",n);
			else printf("1");}
        else printf("%d",gr%n);
    }
    return 0;
}
