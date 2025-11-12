#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;cin>>n>>m;
    int s[n*m];bool b[n*m];
    for(int i=0;i<m*n;i++){
        cin>>s[i];
        b[i]=false;
    }
    b[0]=true;
    for(int i=0;i<n*m;i++){
        for(int j=0;j<n*m-1-i;j++){
            if(s[j]<s[j+1]){
                int temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
                bool tempb=b[j];
                b[j]=b[j+1];
                b[j+1]=tempb;
            }
        }
    }
    int index=0,c=0,r=0;
    for(int i=0;i<m;i++){
        if((i+1)%2==1){
            for(int j=0;j<n;j++){
                if(b[index]==true){
                    c=i+1;
                    r=j+1;
                }
                index++;
            }
        }
        else {
            for(int j=n-1;j>=0;j--){
                if(b[index]==true){
                    c=i+1;
                    r=j+1;
                }
                index++;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
