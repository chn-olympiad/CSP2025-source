
#include<bits/stdc++.h>
using namespace std;
struct pe{
    long long a1,a2,a3;
}a[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        long long n,i1=0,i2=0,i3=0,num1=0,num2=0,num3=0,jian1[50005]={0},jian2[50005]={0},jian3[50005]={0};
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i].a1>>a[i].a2>>a[i].a3;
        for(int i=0;i<n;i++){
            if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){
                num1+=a[i].a1;
                jian1[i1++]=a[i].a1-max(a[i].a2,a[i].a3);
            }
            else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3){
                num2+=a[i].a2;
                jian2[i2++]=a[i].a2-max(a[i].a1,a[i].a3);
            }
            else{
                num3+=a[i].a3;
                jian3[i3++]=a[i].a3-max(a[i].a2,a[i].a1);
            }
        }
        if(i1>n/2){
            sort(jian1,jian1+i1);
            for(int i=0;i<i1-n/2;i++)num1-=jian1[i];
        }
        if(i2>n/2){
            sort(jian2,jian2+i2);
            for(int i=0;i<i2-n/2;i++)num2-=jian2[i];
        }
        if(i3>n/2){
            sort(jian3,jian3+i3);
            for(int i=0;i<i3-n/2;i++)num3-=jian3[i];
        }
        cout<<num1+num2+num3<<endl;
    }
    return 0;
}
