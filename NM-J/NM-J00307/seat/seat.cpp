#include<bits/stdc++.h>
using namespace std;
int a,b;
int r,l=0,k,o,p;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>a>>b;
    int s[b][a];
    int d[a*b+10];
    for(int f=1;f<=a*b;f++){
    	cin>>d[f];
        }
        k=d[1];
        for(int i=a*b;i>=1;i--){
            if(d[i]>d[i-1]){
                p=d[i-1];
                d[i-1]=d[i];
                d[i]=p;
            }
        }
    for(int i=1;i<=b;i++){
        if(i%2==0){
            for(int q=a;q>=1;q--){
                    s[i][q]=d[o];
                if(s[i][q]==k){
                    cout<<i<<" "<<q;
                    return 0;
                }
                o++;
            }
        }
        else{
            for(int q=0;q<a;q++){
                    s[i][q]=d[o];
                if(s[i][q]==k){
                    cout<<i<<" "<<q;
                    return 0;
                }
                o++;
            }
        }
    }
    }
