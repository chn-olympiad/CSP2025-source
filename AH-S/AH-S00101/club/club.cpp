#include<bits/stdc++.h>
using namespace std;
int b[3];
void qin(){
    b[1]=0;
    b[0]=0;
    b[2]=0;
}
int main(){
    int a;
    cin>>a;
    for(int j=0;j<a;j++){
        int n,ans=0;
        cin>>n;
        int arr[3][n];
        int crr[n],mo[n];
        for(int i=0;i<n;i++){
            cin>>arr[0][i]>>arr[1][i]>>arr[2][i];
            int temp[3];
            temp[0]=arr[0][i];
            temp[1]=arr[1][i];
            temp[2]=arr[2][i];
            sort(temp,temp+3);
            ans+=temp[2];
            if(arr[0][i]==temp[2]){
                b[0]++;
                crr[i]=0;
                mo[i]=min(arr[0][i]-arr[1][i],arr[0][i]-arr[2][i]);
            }
            else if(arr[1][i]==temp[2]){
                b[1]++;
                crr[i]=1;
                mo[i]=min(arr[1][i]-arr[0][i],arr[1][i]-arr[2][i]);
            }
            else{
                b[2]++;
                crr[i]=2;
                mo[i]=min(arr[2][i]-arr[1][i],arr[2][i]-arr[0][i]);
            }
        }
        if(max(max(b[0],b[1]),b[2])<=n/2){
            cout<<ans<<endl;
            qin();
            continue;
        }
        int cha=max(max(b[0],b[1]),b[2])-n/2;
        if(max(max(b[0],b[1]),b[2])==b[0]){
            for(int i=0;i<n;i++){
                if(crr[i]!=0){
                    mo[i]=-1;
                }
            }
            sort (mo,mo+n);
            for(int i=0;cha>0;i++){
                if(mo[i]!=-1){
                    ans-=mo[i];
                    cha--;
                }
            }
            qin();
            cout<<ans<<endl;
            continue;
        }
        if(max(max(b[0],b[1]),b[2])==b[1]){
            for(int i=0;i<n;i++){
                if(crr[i]!=1){
                    mo[i]=-1;
                }
            }
            sort (mo,mo+n);
            for(int i=0;cha>0;i++){
                if(mo[i]!=-1){
                    ans-=mo[i];
                    cha--;
                }
            }
            qin();
            cout<<ans<<endl;
            continue;
        }
        if(max(max(b[0],b[1]),b[2])==b[2]){
            for(int i=0;i<n;i++){
                if(crr[i]!=2){
                    mo[i]=-1;
                }
            }
            sort (mo,mo+n);
            for(int i=0;cha>0;i++){
                if(mo[i]!=-1){
                    ans-=mo[i];
                    cha--;
                }
            }
            qin();
            cout<<ans<<endl;
            continue;
        }
    }

    return 0;
}
