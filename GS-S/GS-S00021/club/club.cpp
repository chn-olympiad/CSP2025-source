#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    int num[t][100005][3];
    for(int o=0;o<t;o++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>num[o][i][0];
            cin>>num[o][i][1];
            cin>>num[o][i][2];
        }
    }

    for(int o=0;o<t;o++){
        int con[3]={0,0,0},maxl[n]={};;
        int wait[n]={},k=0,fin=0;
        for(int i=0;i<n;i++){
            maxl[i]=num[o][i][0];
        }
        sort(maxl,maxl+n);
        for(int i=0;i<n;i++){
            if(num[o][i][0]>num[o][i][1]&&num[o][i][0]>num[o][i][2]){
                if(num[o][i][1]==0&&num[o][i][2]==0&&con[0]<n/2){
                    con[0]+=1;
                    fin+=maxl[n-i-1];
                }else{
                    if(con[0]<n/2||n/2==0){
                        con[0]+=1;
                        fin+=num[o][i][0];
                    }else{
                        con[1]+=1;
                        fin+=num[o][i][1];
                    }
                }
            }else if(num[o][i][1]>num[o][i][0]&&num[o][i][1]>num[o][i][2]){
                if(con[1]<n/2||n/2==0){
                    con[1]+=1;
                    fin+=num[o][i][1];
                }else{
                    con[2]+=1;
                    fin+=num[o][i][2];
                }
            }else if(num[o][i][2]>num[o][i][0]&&num[o][i][2]>num[o][i][1]){
                if(con[2]<n/2||n/2==0){
                    con[2]+=1;
                    fin+=num[o][i][2];
                }else{
                    con[0]+=1;
                    fin+=num[o][i][0];
                }
            }else{
                if(num[o][i][0]==num[o][i][1])
                    wait[k]=num[o][i][0];
                else
                    wait[k]=num[o][i][2];
                k++;
            }
        }
        for(int u=0;u<k;u++){
            fin+=wait[u];
        }
        cout<<fin<<endl;
    }
    return 0;
}
