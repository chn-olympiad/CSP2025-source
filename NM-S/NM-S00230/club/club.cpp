#include<bits/stdc++.h>
using namespace std;
int s1[1000010];
int s2[1000010];
int s3[1000010];
int s[1000010][4];
int a[3];
int ii(int o,int p,int q,int r){
    if(o==r){
        return 1;
    }else if(p==r){
        return 2;
    }else{
        return 3;
    }
}
int max2(int x,int y,int z){
    int b[3]={x,y,z};
    sort(b,b+3);
    return b[1];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,num=0;
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
            scanf("%d %d %d",&s1[i],&s2[i],&s3[i]);
            s[i][1]=max(s1[i],max(s2[i],s3[i]));
            s[i][2]=max2(s1[i],s2[i],s3[i]);
            s[i][3]=min(s1[i],min(s2[i],s3[i]));
            num+=s[i][1];
        }
        cout<<num<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
