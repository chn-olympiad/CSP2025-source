#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,c=0,d,e,x,y;
    cin>>a>>b;
    int fs[1000];
    for(int i=1;i<=a*b;i++){
        cin>>fs[i];
    }
    e=fs[1];
    for(int j=1;j<=a*b;j++){
        for(int i=1;i<=a*b;i++){
            if(fs[i]<fs[i+1]){
                c=fs[i];
                fs[i]=fs[i+1];
                fs[i+1]=c;
            }
        }
    }
    int s=1;
    while(fs[s]!=e){
        s++;
    }
    x=s/b;
    if(x%2==1){
        y=s%b;
    }else{
        y=b-s%b;
    }
    cout<<x<<" "<<y;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
