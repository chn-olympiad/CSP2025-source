#include <bits/stdc++.h>
using namespace std;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    int k=0,v=0;
    int y,z;
    vector<int>x;
    vector<int>n;
    for(int i=0;i<t;i++){
     cin>>z;
     n[i]=z;
     for(int j=0;j<z;j++){
        cin>>x[k++];
     }
    }
    for(int j=0;j<t;j++){
        z=n[j];
        vector<int>a;
        for(int i=0;i<z;i++){
            if(i%3==0){
                a[v++]=x[i];
            }
        }
        for(int i=0;i<v+1;i++){
            if(a[i]<a[i+1]){
                y=a[i];
                a[i]=a[i+1];
                a[i+1]=y;
            }
        }
        vector<int>b;
        for(int i=0;i<z;i++){
            if(i%3==1){
                b[v++]=x[i];
            }
        }
        for(int i=0;i<v+1;i++){
            if(b[i]<b[i+1]){
                y=b[i];
                b[i]=b[i+1];
                b[i+1]=y;
            }
        }
        vector<int>c;
        for(int i=0;i<z;i++){
            if(i%3==2){
                c[v++]=x[i];
            }
        }
        for(int i=0;i<v+1;i++){
            if(c[i]<c[i+1]){
                y=c[i];
                c[i]=c[i+1];
                c[i+1]=y;
            }
        }
        long long sum=a[0]+b[0]+c[0]+(a[1]>b[1]?a[1]>c[1]?a[1]:c[1]:b[1]>c[1]?b[1]:c[1]);
        cout<<sum<<endl;
        v=0;
    }

    return 0;
}
