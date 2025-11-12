#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int t;
    long long sum,cnt,cntt,cnttt;
    sum=0;
    cnt=0;
    cntt=0;
    cnttt=0;
    cin>>t;
    if(t==1){
        int n;
        cin>>n;
        int n1=n/2;
        for(int i=1;i<=n;i++){
            int s1,s2,s3;
            cin>>s1>>s2>>s3;
            if(s1>s2>s3||cnt<n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s1>s2>s3||cnt>n1){
                sum=sum+s2;
                cntt++;
                continue;
            }
            else if(s1>s3>s2||cnt<n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s1>s3>s2||cnt>n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s2>s1>s3||cntt<n1){
                sum=sum+s2;
                cntt++;
                continue;
            }
            else if(s2>s1>s3||cntt>n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s2>s3>s1||cntt<n1){
                sum=sum+s2;
                cntt++;
                continue;
            }
            else if(s2>s3>s1||cntt>n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s3>s1>s2||cnttt<n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s3>s1>s2||cnttt>n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s3>s2>s1||cnttt<n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s3>s2>s1||cnttt>n1){
                sum=sum+s2;
                cntt++;
                continue;
            }

      }
        cout<<sum;
    }
    if(t==2){
        for(int o=1;o<=2;o++){
        int n;
        cin>>n;
        int n1=n/2;
        for(int i=1;i<=n;i++){
            int s1,s2,s3;
            cin>>s1>>s2>>s3;
            if(s1>s2>s3||cnt<n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s1>s2>s3||cnt>n1){
                sum=sum+s2;
                cntt++;
                continue;
            }
            else if(s1>s3>s2||cnt<n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s1>s3>s2||cnt>n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s2>s1>s3||cntt<n1){
                sum=sum+s2;
                cntt++;
                continue;
            }
            else if(s2>s1>s3||cntt>n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s2>s3>s1||cntt<n1){
                sum=sum+s2;
                cntt++;
                continue;
            }
            else if(s2>s3>s1||cntt>n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s3>s1>s2||cnttt<n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s3>s1>s2||cnttt>n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s3>s2>s1||cnttt<n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s3>s2>s1||cnttt>n1){
                sum=sum+s2;
                cntt++;
                continue;
            }

      }
        cout<<sum<<endl;
    }
    }
    if(t==3){
        for(int o=1;o<=3;o++){
        int n;
        cin>>n;
        int n1=n/2;
        for(int i=1;i<=n;i++){
            int s1,s2,s3;
            cin>>s1>>s2>>s3;
            if(s1>s2>s3||cnt<n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s1>s2>s3||cnt>n1){
                sum=sum+s2;
                cntt++;
                continue;
            }
            else if(s1>s3>s2||cnt<n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s1>s3>s2||cnt>n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s2>s1>s3||cntt<n1){
                sum=sum+s2;
                cntt++;
                continue;
            }
            else if(s2>s1>s3||cntt>n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s2>s3>s1||cntt<n1){
                sum=sum+s2;
                cntt++;
                continue;
            }
            else if(s2>s3>s1||cntt>n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s3>s1>s2||cnttt<n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s3>s1>s2||cnttt>n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s3>s2>s1||cnttt<n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s3>s2>s1||cnttt>n1){
                sum=sum+s2;
                cntt++;
                continue;
            }

      }
        cout<<sum<<endl;
    }
    }
    if(t==4){
        for(int o=1;o<=4;o++){
        int n;
        cin>>n;
        int n1=n/2;
        for(int i=1;i<=n;i++){
            int s1,s2,s3;
            cin>>s1>>s2>>s3;
            if(s1>s2>s3||cnt<n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s1>s2>s3||cnt>n1){
                sum=sum+s2;
                cntt++;
                continue;
            }
            else if(s1>s3>s2||cnt<n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s1>s3>s2||cnt>n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s2>s1>s3||cntt<n1){
                sum=sum+s2;
                cntt++;
                continue;
            }
            else if(s2>s1>s3||cntt>n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s2>s3>s1||cntt<n1){
                sum=sum+s2;
                cntt++;
                continue;
            }
            else if(s2>s3>s1||cntt>n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s3>s1>s2||cnttt<n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s3>s1>s2||cnttt>n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s3>s2>s1||cnttt<n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s3>s2>s1||cnttt>n1){
                sum=sum+s2;
                cntt++;
                continue;
            }

      }
        cout<<sum<<endl;
    }
    }
    if(t==5){
        for(int o=1;o<=5;o++){
        int n;
        cin>>n;
        int n1=n/2;
        for(int i=1;i<=n;i++){
            int s1,s2,s3;
            cin>>s1>>s2>>s3;
            if(s1>s2>s3||cnt<n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s1>s2>s3||cnt>n1){
                sum=sum+s2;
                cntt++;
                continue;
            }
            else if(s1>s3>s2||cnt<n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s1>s3>s2||cnt>n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s2>s1>s3||cntt<n1){
                sum=sum+s2;
                cntt++;
                continue;
            }
            else if(s2>s1>s3||cntt>n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s2>s3>s1||cntt<n1){
                sum=sum+s2;
                cntt++;
                continue;
            }
            else if(s2>s3>s1||cntt>n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s3>s1>s2||cnttt<n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s3>s1>s2||cnttt>n1){
                sum=sum+s1;
                cnt++;
                continue;
            }
            else if(s3>s2>s1||cnttt<n1){
                sum=sum+s3;
                cnttt++;
                continue;
            }
            else if(s3>s2>s1||cnttt>n1){
                sum=sum+s2;
                cntt++;
                continue;
            }

      }
        cout<<sum<<endl;
    }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
