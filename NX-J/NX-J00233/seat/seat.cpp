#include<bits/stdc++.h>
using namespace std;
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int a,b,c,d[105],e,n,m,u=0,g=0,o=0;
cin>>n>>m;
c=n*m;
for(int i=1;i<=c;i++){
        cin>>d[i];

}
a=d[1];
for(int i=1;i<=c;i++){
    for(int j=1;j<=c;j++){
        if(d[j]>d[j+1]){
            e=d[j];
            d[j]=d[j+1];
            d[j+1]=e;

    }
}
}
for(int i=1;i<=c;i++){
    d[i]=d[c];
    c--;
}
for(int i=1;i<=c;i++){
        if(a==d[i]){
            b=i;

        }
}
if(b<=m){
    cout<<"1"<<" "<<b;
    return 0;
}
o=b/m;
u=b%m;
cout<<o<<" "<<u;
if(o%2==0){
    cout<<o+1<<" "<<m-u+1;
    return 0;
}
if(o%2==1){
    cout<<o+1<<" "<<u;
    return 0;
}
return 0;
}

