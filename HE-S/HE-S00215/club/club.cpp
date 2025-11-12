#include<iostream>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int n;
    cin>>n;
    int a[n][3];
    int sum=0,s1=0,s2=0,s3=0;
    for(int l=0;l<t;l++){
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<n;i++){
            if(a[i][1]<=a[i][0]&&a[i][2]<=a[i][0]){
                s1++;
                if(s1<=(n/2)){
                    sum+=a[i][0];
                }
                else{
                    if(a[i][1]>=a[i][2]){
                        sum+=a[i][1];
                    }
                    else{
                        sum+=a[i][2];
                    }
                }
            }
            else if(a[i][0]<=a[i][1]&&a[i][2]<=a[i][1]){
                s2++;
                if(s2<=(n/2)){
                    sum+=a[i][1];
                }
                else{
                    if(a[i][0]>=a[i][2]){
                        sum+=a[i][0];
                    }
                    else{
                        sum+=a[i][2];
                    }
                }
            }
            else if(a[i][0]<=a[i][2]&&a[i][1]<=a[i][2]){
                s3++;
                if(s3<=(n/2)){
                    sum+=a[i][2];
                }
                else{
                    if(a[i][0]>=a[i][1]){
                        sum+=a[i][0];
                    }
                    else{
                        sum+=a[i][1];
                    }
                }
            }
        }
    }
    for(int l=0;l<t;l++){
        cout<<sum<<endl;
    }

    return 0;
}
