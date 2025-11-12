//GZ-S00342 贵阳市第三实验中学 王钦澄
#include<bits/stdc++.h>
using namespace std;
int n,q,t,y;
string a[5000005],b[5000005],c,d,s1,s2;
int main(){
    freopen("replace.in",r,stdin);
    freopen("replace.out",w,stdout);
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    for(int i=0;i<q;i++){
        int e=0;
        cin >> c >> d;
        if(c.size()!=d.size()){
            cout << 0;
            continue;
        }
        y=c.size()-1;
        while(c[t]==d[t]){
            t++;
        }
        while(c[y]==d[y]){
            y--;
        }
        for(int j=t;j<=y;j++){
            s1+=c[j];
            s2+=d[j];
        }
        for(int j=0;j<=n;j++){
            if(s1.size()>a[j].size()){
                continue;
            }
            for(int k=0;k<=a[j].size();k++){
                if(a[j][k]==s1[0]){
                    int h=1;
                    for(int l=k;l<k+s1.size();l++){
                        if(a[j][l]!=s1[l-k] || b[j][l]!=s2[l-k]){
                            h=0;
                            break;
                        }
                    }
                    if(h==1){
                        for(int l=t-k;l<a[j].size();l++){
                            if(a[j][l]!=c[l] || b[j][l]!=d[l]){
                                h=0;
                                break;
                            }
                        }
                        if(h==1){
                            e++;
                        }
                    }
                }
            }
        }
        cout << e;
    }
    return 0;
}
