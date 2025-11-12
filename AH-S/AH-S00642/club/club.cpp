#include <bits/stdc++.h>
using namespace std;
int a[1000005][4];
bool better(int clubmax,int i,int thisclub){
    int b=max(a[clubmax][(thisclub)+1%3],a[clubmax][(thisclub)+2%3]);
    int c=max(a[i][(thisclub)+1%3],a[i][(thisclub)+2%3]);
    if(b>c) return true;
    else return false;
}
long long n1(int n){
    long long club[4]={0},clubsam[4]={0};//人数，sam满意度
    while(club[1] < n/2 || club[2] < n/2 || club[3] < n/2){
        for(int j=1;j<=3;j++){
            if(club[j] < n/2){
                int clubmax=0;
                for(int k=n;k>=1;k--){
                    if(a[clubmax][j]==a[k][j]){
                        if(better(clubmax,k,j))
                            clubmax=k;
                            continue;
                    }
                    if(a[clubmax][j]<a[k][j]){
                        clubmax=k;
                    }
                }
                club[j]++;
                clubsam[j]+=a[clubmax][j];
                a[clubmax][1]=0;
                a[clubmax][2]=0;
                a[clubmax][3]=0;
            }
        }
    }
    return clubsam[1]+clubsam[2]+clubsam[3];
}
long long n2(int n){
    long long club=0,clubsam=0;//人数，sam满意度
        int clubmax=0;
        while(club < n/2){
            for(int k=1;k<=n;k++){
                if(a[clubmax][1]<a[k][1]){
                    clubmax=k;
                }
            }
            club++;
            clubsam+=a[clubmax][1];
            a[clubmax][1]=0;
        }
    return clubsam;
}
long long n3(int n){
    long long club[3]={0},clubsam[3]={0};//人数，sam满意度
        while(club[1] < n/2 || club[2] < n/2){
            int clubmax=0;
            for(int i=1;i<=n;i++){
                if(a[clubmax][1]<a[i][1]){
                    clubmax=i;
                }
            }
            club[1]++;
            clubsam[1]+= a [clubmax] [1];
            a[clubmax][1]=0;
            a[clubmax][2]=0;
            clubmax=0;
            for(int i=1;i<=n;i++){
                if(a[clubmax][2]<a[i][2]){
                    clubmax=i;
                }
            }
            club[2]++;
            clubsam[1]+=a[clubmax][2];
            a[clubmax][1]=0;
            a[clubmax][2]=0;
        }
    return clubsam[1]+clubsam[2];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for (int i=1;i<=t;i++){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        if(a[1][3]==0){
            if(a[1][2]==0){
                cout<<n2(n)<<endl;
                continue;
            }
            cout<<n3(n)<<endl;
            continue;
        }
        cout<<n1(n)<<endl;
    }
    return 0;
}