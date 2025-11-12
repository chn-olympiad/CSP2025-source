#include <bits/stdc++.h>
#define st string
#define N 1000005
using namespace std;
st a;
int b[N];
long long cnt,num;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    num = a.length();
    for(int i=0;i<num;i++){
        if(a[i]=='1'){
            b[cnt]=1;
            cnt++;
        }else if(a[i]=='2'){
            b[cnt]=2;
            cnt++;
        }else if(a[i]=='3'){
            b[cnt]=3;
            cnt++;
        }else if(a[i]=='4'){
            b[cnt]=4;
            cnt++;
        }else if(a[i]=='5'){
            b[cnt]=5;
            cnt++;
        }else if(a[i]=='6'){
            b[cnt]=6;
            cnt++;
        }else if(a[i]=='7'){
            b[cnt]=7;
            cnt++;
        }else if(a[i]=='8'){
            b[cnt]=8;
            cnt++;
        }else if(a[i]=='9'){
            b[cnt]=9;
            cnt++;
        }else if(a[i]=='0'){
            b[cnt]=0;
            cnt++;
        }

    }
    sort(b,b+cnt);
    for(int i=cnt-1;i>=0;i--){
        cout<<b[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}
