#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500001]={};
long long j;
long long bj[500001][501]={};
long long d;
long long s[500001];
long long k1[501];
long long ans;
int c;
long long o=0;
long long bjj[500001];
int main(){
    //freopen("xor.in","r",stdin);
    //  freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        j=0;
        while(1){
            if(a[i]==0){
                break;
            }
            j++;
            if(a[i]%2==1){
                bj[i][j]=1;
                a[i]=a[i]/2;
            }
            else{
                bj[i][j]=0;
                a[i]=a[i]/2;
            }
        }
        s[i]=j;
    }
    j=0;
   while(1){
        if(k==0){
            break;
        }
        j++;
        if(k%2==1){
            k1[j]=1;
            k=k/2;
        }
        else{
            k1[j]=0;
            k=k/2;
        }
    }
    ans=j;
    for(int i=1;i<=n;i++){//tou
        for(int j=i+1;j<=n;j++){//wei
            for(int r=i+1;r<j;r++){//fanwei
                for(int p=1;p<=s[r];p++){//yihuo
                    if(bj[r][p]==bj[r+1][p]){
                        bj[r+1][p]=0;
                    }
                    else{
                        bj[r+1][p]=1;
                    }
                }
               for(int p=1;p<=s[r];p++){//yihuo
                    if(bjj[r]==1){
                        break;
                    }
                    if(bj[r][p]==k1[p]){
                        c=0;
                        bjj[r]=1;
                    }
                    else{
                        c=1;
                        bjj[r]=1;
                        break;
                    }
                }
                if(c!=1){
                    o++;
                }
                else{
                    c=0;
                }

            }



        }
    }
    cout<<o;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
