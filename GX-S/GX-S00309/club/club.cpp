#include<bits/stdc++.h>
using namespace std;
int t,n,a1[200000],a2[200000],a3[200000],a[200000][5],ans,tong[2000000],f[200000][5];
/*bool che(int aa,int b){
int l1[200000],l2[200000];
for(int i=1;i<=n;i++)
for(int j=1;j<=3;j++){
if(a[i][j]==aa)

}



}*/
int main(){
    freopen("club.in","r",stdin);
     freopen("club.out","w",stdout);
cin>>t;
for(int aaa=1;aaa<=t;aaa++){
cin>>n;

if(n==2){
        int as=-41;
    cin>>a[1][1]>>a[1][2]>>a[1][3]>>a[2][1]>>a[2][2]>>a[2][3];
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++){
            if(i==j)continue;
            else{
                as=max(as,a[1][i]+a[2][j]);

            }

        }
cout<<as<<endl;
continue;
}

for(int i=1;i<=n;i++){
cin>>a1[i]>>a2[i]>>a3[i];
}
for(int i=1;i<=n;i++){

    f[n-i+1][1]=a1[i];
    f[n-i+1][2]=a2[i];
    f[n-i+1][3]=a3[i];

}
sort(a1+1,a1+1+n);
sort(a2+1,a2+1+n);
sort(a3+1,a3+1+n);
for(int i=1;i<=n;i++){

    a[n-i+1][1]=a1[i];
    a[n-i+1][2]=a2[i];
    a[n-i+1][3]=a3[i];

}
for(int i=1;i<=n/2;i++)
for(int j=1;j<=3;j++){


}


int cm=0;

n/=2;



for(int i=1;i<=n;i++)
for(int j=1;j<=3;j++){
        cm++;
    tong[cm]=a[i][j];
}
sort(tong+1,tong+cm+1);
ans=0;
for(int i=1;i<n*2;i++){
ans+=tong[cm-i+1];
//cout<<tong[cm-i+1]<<" ";
}

cout<<ans<<endl;
}











return 0;
}
