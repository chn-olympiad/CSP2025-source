#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m,ind,cnt,asy;
    bool diff=true;
    string a[n],b[n],c[m],d[m];
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    for(int i=0;i<m;i++){
        cin >> c[i] >> d[i];
        diff = true;
        for(int q=0;q<n;q++){for(int j=0;j<c.size();j++){
            if(c[i][j]!=d[i][j]){
                ind=j;
                for(int z=0;z<n;z++){
                    if(a[z]==c[i][j]){
                        cnt++;
                        diff=false;
                        c[i][j]=b[z];
                    }

                }
                c[i][j+1]=b[j+1];

            }
            if(diff == false && d[i]!=c[i]){
                c[i]= d[i];
                ind = i+1;
            }
        for(int z=0;z<m;z++){
            if(d[i][j]!=b[q]){
                continue;
            }
        }
        if(a[q]==c[i][j]+c[i][j+1])
        }}
        cout << cnt << endl;
    }
    )


    return 0;
}
