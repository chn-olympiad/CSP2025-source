#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int s;
    cin >> s;
    if(s<10){
        cout << s;
        return 0;
    }
    int q=s,c[100100],a[100100],f=1;
    while(q!=0){
        a[f]=q%10;
        f++;
        q = q/10;
    }
    for(int i=1;i<=f;i++) c[a[i]]++;
    int num,m,n=1;
    for(int i=0;i<=f;i++){
        while(c[i]!=0){
            if(i == 0){
                n *= 10;
            }
            else m=i*10;
            c[i]--;
        }
        num = (num+m)*n;
        n=1;
    }
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;

}
