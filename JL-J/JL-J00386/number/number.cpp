#include<bits/stdc++.h>
using namespace std;
char a[1005];
int b=0,c=0,d,e,f[1005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>a[b]){
        b++;
    }
    for(int i=0;i<b;i++){
        for(int q=1;q<=9;q++){
            if(a[i]==q){
                f[c]=int(a[i]);
                c++;
            }
        }
    }
for(int w=0;w<=c;w++){
    for(int r=0;r<=c;r++){
        if(f[w]<f[r]){
            f[w]=f[r];

        }
    }
}
for(int y=0;y<=c;y++){
    cout<<f[y];
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
