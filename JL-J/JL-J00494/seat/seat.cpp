#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s=n*m,rw,fs[s+5],ls;
    for(int i=1;i<=s;i++){
        cin>>fs[i];
        if(i==1){
            rw=fs[i];
        }
    }
    int s1=s;
    while(s){
        int c=1;
        while(c<s){
            if(fs[c+1]>fs[c]){
                ls=fs[c];
                fs[c]=fs[c+1];
                fs[c+1]=ls;

            }
            c++;
        }
        s--;
    }
    int er[n+5][m+5];
    int z=1;
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>=1;j--){
                er[j][i]=fs[z];
                if(er[j][i]==rw){
                    cout<<i<<" "<<j;
                    return 0;
                }
                z++;
            }
        }
        else{
            for(int j=1;j<=n;j++){
                er[j][i]=fs[z];
                if(er[j][i]==rw){
                    cout<<i<<" "<<j;
                    return 0;
                }
                z++;
            }
        }
    }

    return 0;
}
