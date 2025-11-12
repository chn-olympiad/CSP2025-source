#include<bits/stdc++.h>
using namespace std;
long long T;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        long long n,h;
        long long a1[100005]={},a2[100005]={},a3[100005]={};
        long long s1=0,s2=0,s3=0,sum=0;
        cin>>n;
        h=n/2;
        for(int i=1;i<=n;i++){
            long long a11,a22,a33,maxx;
            cin>>a11>>a22>>a33;
            maxx=max(a11,max(a22,a33));
            if(maxx==a11){
                s1++;
                a1[s1]=min(a11-a22,a11-a33);
            }
            else if(maxx==a22){
                s2++;
                a2[s2]=min(a22-a11,a22-a33);
            }
            else if(maxx==a33){
                s3++;
                a3[s3]=min(a33-a22,a33-a11);
            }
            sum+=maxx;
        }
        if(s1>=h){
            sort(a1+1,a1+s1+1);
            for(int i=1;i<=s1-h;i++){
                sum-=a1[i];
            }
        }
        if(s2>=h){
            sort(a2+1,a2+s2+1);
            for(int i=1;i<=s2-h;i++){
                sum-=a2[i];
            }
        }
        if(s3>=h){
            sort(a3+1,a3+s3+1);
            for(int i=1;i<=s3-h;i++){
                sum-=a3[i];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
