#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[222222],b[222222];
int c[222222];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
    }
    for(int op=1;op<=q;op++){
        string x,y;
        cin >> x >> y;
        int sum=0;
        if(x.length()==y.length()){
        for(int i=1;i<=n;i++){
            int yu=1,kl=0;
            if(a[i].length()>x.length()){

            }else{
            for(int j=0;j<x.length();j++){
                if(x[j]==a[i][0]){
                    kl++;
                    int f=0;
                    for(int k=0;k<a[i].length();k++){
                        if(x[j+k]!=a[i][k]){
                            f=1;
                            break;
                        }
                    }
                    if(f==0){
                        int we=0;
                        for(int k=0;k<a[i].length();k++){
                            if(y[j+k]!=b[i][k]){
                                we=1;
                                break;
                            }
                        }
                        if(we==0){
                            yu=0;
                        }else{
                            yu=1;
                        }
                    }else{
                        yu=1;
                    }
                    j+=a[i].length()-1;
                }else if(x[j]!=y[j]){
                    yu=1;
                    break;
                }
            }
            if(yu==0&&kl<=1){
                sum++;
            }
        }
            }
        cout << sum << endl;
        }else{
            cout << 0 << endl;
        }
    }
        return 0;
    }
