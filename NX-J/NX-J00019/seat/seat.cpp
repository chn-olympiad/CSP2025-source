#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,m,a,c=0,d,w;
    cin>>n>>m;
    a = m * n;
    int b[a]={0};
    int len=m*n;
    for(int i=0;i<a;i++){
        cin>>b[i];
        d=b[0];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(b[c]<=b[c+i]){
                w = b[c];
                b[c]=b[c+i];
                b[c+i]=w;
            }
            else if(b[c]<=b[c+i+1]){
                w = b[c];
                b[c]=b[c+i+1];
                b[c+i+1]=w;
            }


        }
    }
    for(int i=1;i<=len;i++){
        sort(b+0,b+0);
        if(b[i-1]==d){
            if(i<n&&i%2==1){
                cout<<i<<' '<<i%3;
                break;
            }
            else if(i>n&&i%2==1){
                cout<<i-n<<' '<<i%3;
                break;
            }
            else if(i<n&&i%2==0){
                cout<<i<<' '<<i;
                break;
            }
            else if(i==n&&i%2==1){
                cout<<i/2<<' '<<i%3;
                break;
            }
            else if(i==n&&i%2==0&&i>2){
                cout<<i<<' '<<i;
                break;
            }
            else if(i==n&&i%2==0&&i-1<2){
                cout<<i/2<<' '<<i;
                break;
            }
            else{
                cout<<i-n<<' '<<i;
                break;
            }
        }
    }


    fclose(stdin);
    fclose(stdout);

    return 0;
}
