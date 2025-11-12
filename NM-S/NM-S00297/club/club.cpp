#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100005][3];
int ma[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,a1=0,a2=0,a3=0,s1=0,s2=0,s3=0;
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
            ma[j]=max({a[j][1],a[j][2],a[j][3]});
            if(a[j][1]==ma[j]){
                if(a1<=n/2){
                    a1++;
                    s1+=a[j][1];
                    continue;
                }
                else if(a[j][2]>a[j][3]){
                    if(a2<=n/2){
                        a2++;
                        s2+=a[j][2];
                        continue;
                    }
                    else{
                        a3++;
                        s3+=a[j][3];
                        continue;
                    }
                }
            }
            if(a[j][2]==ma[j]){
                if(a2<=n/2){
                    a2++;
                    s2+=a[j][2];
                    continue;
                }
                else if(a[j][1]>a[j][3]){
                    if(a1<=n/2){
                        a1++;
                        s1+=a[j][1];
                        continue;
                    }
                    else{
                        a3++;
                        s3+=a[j][3];
                        continue;
                    }
                }
            }
            if(a[j][3]==ma[j]){
                if(a3<=n/2){
                    a3++;
                    s3+=a[j][3];
                    continue;
                }
                else if(a[j][1]>a[j][2]){
                    if(a1<=n/2){
                        a1++;
                        s1+=a[j][1];
                        continue;
                    }
                    else{
                        a2++;
                        s2+=a[j][2];
                        continue;
                    }
                }
            }
        }
        cout<<s1+s2+s3<<endl;
    }
}
