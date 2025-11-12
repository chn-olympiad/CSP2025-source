#include<bits/stdc++.h>
using namespace std;
int t,n,sum,m;
int a[100005][4];
int b[100005];
bool cmd (int q,int w){
    return q>w;
}

int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int p=0;p<t;p++){
        vector <int> x,y,z,k;
        cin>>n;
        sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]!=0&&max(a[i][1],max(a[i][2],a[i][3]))==a[i][1]){
                x.push_back(a[i][1]);
            }
            else if(a[i][2]!=0&&a[i][2]==max(a[i][1],max(a[i][2],a[i][3]))){
                y.push_back(a[i][2]);
            }
            else if(a[i][3]!=0&&a[i][3]==max(a[i][1],max(a[i][2],a[i][3]))){
                z.push_back(a[i][3]);
            }
        }
        if(n==2){
            for(int i=1;i<3;i++){
                for(int j=1;j<=3;j++){
                    if(i!=j){
                        sum=max(a[0][i]+a[1][j],sum);
                    }
                }
            }
            cout<<sum;
            continue;
        }
        sort(x.begin(),x.end(),cmd);
        sort(y.begin(),y.end(),cmd);
        sort(z.begin(),z.end(),cmd);
        int q=x.size(),w=y.size(),e=z.size(),l=0;
        for(int j=0;j<max(q,n/2);j++){
            if(j<n/2&&j<q){
                sum+=x[j];
            }else if(j>=q&&j<n/2){
                l++;
            }else if(j>=n/2&&j<q){
                k.push_back(x[j]);
            }
        }
        for(int j=0;j<max(w,n/2);j++){
            if(j<n/2&&j<w){
                sum+=y[j];
            }else if(j>=w&&j<n/2){
                l++;
            }else if(j>=n/2&&j<w){
                k.push_back(y[j]);
            }
        }
        for(int j=0;j<max(e,n/2);j++){
            if(j<n/2&&j<e){
                sum+=z[j];
            }else if(j>=e&&j<n/2){
                l++;
            }else if(j>=n/2&&j<e){
                k.push_back(z[j]);
            }
        }
        sort(k.begin(),k.end(),cmd);
        int u=k.size();
        for(int j=0;j<min(l,u);j++){
            sum+=k[j];
        }
        cout<<sum<<endl;
    }

    return 0;
}
