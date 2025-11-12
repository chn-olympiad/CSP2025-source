#include<bits/stdc++.h>
using namespace std;
int n,m,me,place=1; //n=hang m=lie
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
int all=n*m,a[all+10];
cin>>me;//fenshu
for(int i=1;i<=all-1;i++){
    cin>>a[i]; //a[1],first
    if(a[i]>me) place++;
}
//weizhi
int c,r;//c=hang r=lie
if(place%n==0){ //tepan
        c=place/n;
        if(c%2==0) r=1;
        else r=n;
}else{
        c=place/n+1;
        if(c%2==0){ //oushu lie
            r=n-place%n+1;
        }else{
            r=place%n;
        }
    }

cout<<c<<' '<<r;

fclose(stdin);fclose(stdout);
return 0;
}
