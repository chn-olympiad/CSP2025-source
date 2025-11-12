#include<bits/stdc++.h>
using namespace std;
int o(int a){
int e = 0;
if (a>10){
    a/10;
    e++;
}
else {
    e++;
}
return e;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    int a,b,c,h;
    int f = 0;
    int g = 1;
    int d[180808],e[1424323];
    cin >>a>>b;
    cin >>c;


    for (int j = o(c);j>=0;j--){
    if(c%10 == 0){
        c = c/10;
        d[j] = 0;
        f++;
    }
    else {d[j] =1;}
    }
    for (int i = 0;i<a;i++){
        cin >>d[i];
        if (d[i] <=f){h++;}
    }

    for (int k = 1;k<=(a-f);k++){
        g *= k;
    }
    cout << g;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
