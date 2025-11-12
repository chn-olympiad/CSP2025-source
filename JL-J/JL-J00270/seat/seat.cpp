#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat,out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[101]={};
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int x=a[0];
    int num=1;
    for(int i=0;i<n*m;i++){
        if(a[i]>x){
            num++;
        }
    }
    if((num%n)==0){
        if((num/n)%2==0){
            cout<<num/n<<" "<<1<<endl;
        }else if((num/n)%2!=0){
            cout<<num/n<<" "<<n<<endl;
        }
    }else if((num%n)!=0){
        if(n%2==0){
            cout<<num/n+1<<" "<<n+1-(num%n)<<endl;
        }else if((num/n)%2!=0){
            cout<<num/n+1<<" "<<n+1-(num%n)<<endl;
        }else{
            cout<<num/n+1<<" "<<num%n<<endl;
        }

    }
    fclose(stdin);
    fclose(stdout);
return 0;
}
