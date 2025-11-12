#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[1001],newa[1001],b[1001],l=1,h=1;
    cin >> n >> m;
    for(int i = 1;i<=n*m;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    int num = a[1];
    int cnt = 1;
    for(int i = 1;i<=n*m;i+=m){
        if(cnt%2!=0){
            for(int j = i+1;j<i+m;j++){
                if(a[i]<a[j]){
                    a[j] = b[i];
                    a[i] = b[j];
                    b[j] = a[j];
                    b[i] = a[i];
                }
            }
        }
        else{
            for(int j = i+1;j<i+m;j++){
                if(a[i]>a[j]){
                    a[j] = b[i];
                    a[i] = b[j];
                    b[j] = a[j];
                    b[i] = a[i];
        }}}
        cnt +=1;
    }
    for(int i= 1;;i++){
        if(h>m){
            h -= m;
            l += 1;
        }
        if(a[i]==num){
            cout << l << " " << h;
            break;
        }
        h++;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
