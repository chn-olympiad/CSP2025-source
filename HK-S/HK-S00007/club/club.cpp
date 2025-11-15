#include<bits/stdc++.h>
using namespace std;
int main(){
    fstream("club.in",ios_base::in);
    fstream("club.out",ios_base::out);
    int t;   
    cin>>t;
    for(int i=0;i<=t-1;i++){
        int n;
        cin>>n;
        int a[500],b[500],c[500];
        for(int j=0;j<=n-1;j++){
          cin>>a[j]>>b[j]>>c[j];
        }
        int max1,max2;
        if(max(a[0],max(b[0],c[0]))==a[0]){
          max1=a[0]+max(b[1],c[1]);
        }
        else if(max(a[0],max(b[0],c[0]))==b[0]){
          max1=b[0]+max(a[1],c[1]);
        }
        else if(max(a[0],max(b[0],c[0]))==c[0]){
          max1=c[0]+max(b[1],a[1]);
        }
        if(max(a[1],max(b[1],c[1]))==a[1]){
          max1=a[1]+max(b[0],c[0]);
        }
        else if(max(a[1],max(b[1],c[1]))==b[1]){
          max1=b[1]+max(a[0],c[0]);
        }
        else if(max(a[1],max(b[1],c[1]))==c[1]){
          max1=c[1]+max(b[0],a[0]);
        }
        cout<<max(max1,max2)<<endl;
    } 
    return 0;
}