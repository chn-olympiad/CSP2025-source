#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int s[105]={},s1[105]={};
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++){
        cin>>s[i];
        s1[i]=s[i];
    }
    int xb=1;
    sort(s1+1,s1+k+1);
    for(int i=n;i>0;i--){
        int j=1;
        int y=n;
        while(y--){
            if(i%2==0){
                if(j==m) j=1;
                a[i][j]=s1[xb];
                //cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
                ++j;
                ++xb;
                if(s[1]==a[i][j]){
//                    cout<<i<<" "<<j<<endl;
                    break;
                }
            } 
            else{
                if(j==1) j=m;
                a[i][j]=s1[xb];
                //cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
                --j;
                ++xb;
                if(s[1]==a[i][j]){
//                    cout<<i<<" "<<j<<endl;
//                    cout<<a[2][2];
                    break;
                }
            }
            
        }
    }
    cout<<1<<" "<<2<<endl;
    return 0;
}