#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t,n,maxcount[100000]=0,o=0,p=0,q=0;
int a[100000][3]=0;
cin>>t;
for(int x=0;x<t;x++){
    cin>>n;
for(int i=0;i<n;i++){
for(int j=0;j<3;j++){
        cin>>a[i][j];
        if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
            o++;
            maxcount[i]=maxcount[i]+a[i][0];
            if(o>n/2){
                maxcount[i]=maxcount[i]-a[i][0];
                o--;
                if(a[i][1]>a[i][2]){
                    maxcount[i]=maxcount[i]+a[i][1];
                    p++;
                }
                else{
                    maxcount[i]=maxcount[i]+a[i][2];
                    q++;
                }
            }
        }
        else if(a=[i][0]>a[i][1]&&a[i][0]<a[i][2]){
            q++;
            maxcount[i]=maxcount[i]+a[i][2];
            if(q>n/2){
                 maxcount[i]=maxcount[i]-a[i][2];
                q--;
                if(a[i][1]>a[i][0]){
                    maxcount[i]=maxcount[i]+a[i][1];
                    p++;
                }
                else{
                    maxcount[i]=maxcount[i]+a[i][0];
                    o++;
                }
            }
        }
        else{
            p++;
            maxcount[i]=maxcount[i]+a[i][1];
            if(p>n/2){
                 maxcount[i]=maxcount[i]-a[i][1];
                p--;
                if(a[i][0]>a[i][2]){
                    maxcount[i]=maxcount[i]+a[i][0];
                    o++;
                }
                else{
                    maxcount[i]=maxcount[i]+a[i][2];
                    q++;
                }
            }
            }
}
cout<<maxcount[i]<<endl;
}
}
return 0;
}
