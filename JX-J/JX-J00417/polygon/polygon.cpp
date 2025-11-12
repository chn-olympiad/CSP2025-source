#include <bits/stdc++.h>
using namespace std;
int qin[100000][5002]={},wei=1;
string genq[100000]={};
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,he,ans0=0,ans=0;cin>>n;
    int gun[n+1];
    for(int i=1;i<=n;i++){
        cin>>gun[i];
        he+=gun[i];
    }
    sort(gun+1,gun+1+n);
    if(he>2*gun[n]){
        ans0++;
    }
    for(int i=1;i<=n;i++){
        if(i==n){
            if(he-gun[i]>2*gun[n-1]){
                ans0++;
                string t="";
                qin[wei][0]=n-1;
                qin[wei][5001]=he-gun[i];
                for(int j=1;j<=n-1;j++){
                    t+=(gun[j]+'0');
                    qin[wei][j]=gun[j];
                }
                genq[wei]=t;
                wei++;
            }
        }
        else{
            if(he-gun[i]>2*gun[n]){
                ans0++;
                string t="";
                qin[wei][0]=n-1;
                qin[wei][5001]=he-gun[i];
                for(int j=1;j<=n-1;j++){
                    t+=(gun[j]+'0');
                    if(j<i)qin[wei][j]=gun[j];
                    else qin[wei][j]=gun[j+1];
                }
                genq[wei]=t;
                wei++;
            }
        }
    }
    for(int a=1;a<=wei;a++){
        if(qin[a][0]<=3)continue;
        for(int i=1;i<=qin[a][0];i++){
            if(i==qin[a][0]){
                if(qin[a][5001]-qin[a][i]>2*qin[a][qin[a][0]-1]){
                    ans++;
                    qin[wei][5001]=qin[a][5001]-qin[a][i];
                    qin[wei][0]=qin[a][0]-1;
                    for(int j=1;j<=qin[a][0]-1;j++){
                        qin[wei][j]=qin[a][j];
                    }
                    wei++;
                }
            }
            else{
                if(qin[a][5001]-qin[a][i]>2*qin[a][qin[a][0]]){
                    ans++;
                    qin[wei][5001]=qin[a][5001]-qin[a][i];
                    qin[wei][0]=qin[a][0]-1;
                    for(int j=1;j<=qin[a][0]-1;j++){
                        if(j<i)qin[wei][j]=qin[a][j];
                        else qin[wei][j]=qin[a][j+1];
                    }
                wei++;
                }
            }
        }
    }
    cout<<ans+ans0;
    return 0;
}
