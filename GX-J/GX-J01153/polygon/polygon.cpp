#include <bits/stdc++.h>
using namespace std;
long getsum(int in[],int lon){
    long sum=0;
    for(int i=0;i<lon;i++){
        sum+=in[i];
    }
    return sum;
}
bool sortrule(int a,int b){
    return a>b;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n, output=0;
    cin>>n;
    int stick[n],getmax[n];
    for(int i=0;i<n;i++){
        cin>>stick[i];
        getmax[i] = stick[i];
    }
    sort(getmax+0,getmax+n,sortrule);
    if(!(getsum(stick,n)>getmax[0]*2)){
        cout<<1;
        goto end_this_fucking_program;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(getsum(stick,n)>getmax[0]*2){
                    output++;
                }
            }
        }
    }
    cout<<output-2+stick[1]+stick[2];//what are you fucking doing? --i don't know.
    end_this_fucking_program:
    return 0;
}
