#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t,n;
cin>>t;
int totalans[t];
for(int i=0;i<t;i++){
    cin>>n;
    int satis[n][4];
    int ans=0;
    for(int j=0;j<n;j++){
        cin>>satis[j][1]>>satis[j][2]>>satis[j][3];
    }
    if(n>=1){
        int maxgr=n/2;
        int group1[maxgr+1],numpers=0;
        int mingr=114514,minpos;
        bool detected=0;
        for(int j=0;j<n;j++){
            if(numpers<maxgr){
                numpers++;
                group1[j]=satis[j][1];
                //cout<<"add"<<group1[j]<<endl;
            }else{
                if(detected==0){
                    int mini=114514;
                    for(int k=0;k<=maxgr;k++){
                        if(group1[k]<mini){
                            mini=group1[k];
                            minpos=k;
                        }
                    }
                    mingr=mini;
                    detected=1;
                }

                if(satis[j][1]>mingr){
                        //cout<<"no"<<group1[minpos];
                        group1[minpos]=satis[j][1];
                        //cout<<"replace"<<group1[minpos]<<endl;
                    int mini=114514;
                    for(int k=0;k<=maxgr;k++){
                        if(group1[k]<mini){
                            mini=group1[k];
                            minpos=k;
                        }
                    }
                    mingr=mini;
                }
            }
        }

        for(int k=0;k<maxgr;k++){
            ans+=group1[k];
            //cout<<"ans"<<group1[k]<<endl;
        }
        totalans[i]=ans;
    }
}
for(int i=0;i<t;i++){
    cout<<totalans[i]<<endl;
}
return 0;
}
