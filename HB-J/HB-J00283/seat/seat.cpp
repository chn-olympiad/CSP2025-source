#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[1000003],n,m,c=0,r=0,f=0,p=0;
    cin >> n,m;
    for (int i = 1; i <= n*m; i++){
        cin >> a[i];
        f=a[1];
    }
    sort(a+1,a+1+n*m,cmp);
    for (int i = 0; i <= n*m; i++){
        if(a[i]==f){
            p=i;
            if(p%n>0){
                int b=p%n;
                if((p/n)%2!=0){
                    r=p/n+1;
                    c=b;
                }else{
                    r=p/n;
                    c=n-b+1;
                }
            }else{
                if((p/n)%2!=0){
                    r=p/n+1;
                    c=n;
                }else{
                    r=p/n;
                    c=1;
                }
            }
        }else{
            break;
        }
    }
    cout << c << " " << r;
    cout << endl;
    return 0;
}