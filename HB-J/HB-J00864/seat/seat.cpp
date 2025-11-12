#include <bits/stdc++.h>
using namespace std;
int m,n,man,number;                                                                                                                    ;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n*m;i++){
        cin >> a[i];
    }
    a[1] = man;
    for(int i=1;i<=105;i++){
        if(a[i]>a[i-1]){
            switch(a[i-1],a[i]);
            i-=2;
        }
    }
    for(int i=1;i<=105;i++){
        if(a[i]==man){
            number = i;
        }
    }
    if(number+3/n%2==1){
        cout << number+3/n << ' ' << number%n;
    }else{
        cout << number+3/n << ' ' << n-number%n;
    }
    return 0;
}
