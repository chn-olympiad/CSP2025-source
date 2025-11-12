#include<bits/stdc++.h>
using namespace std;
int flag=0;
void meijv1(long long n,int s[199999][5],char biaoji[199999][5],int a1,int b1,int c1,int maxx){
    int a=a1;
    int b=b1;
    int c=c1;
    int maxxx=maxx;
    int minn=39999,mint;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if((s[i][1]-s[i][2])<minn&&biaoji[i][2]!='*'){
                minn=s[i][1]-s[i][2];
                mint=i;
            }
        }
        maxx=maxx-minn;
        if(biaoji[mint][1]=='a'){
            a1--;
        }
        if(biaoji[mint][1]=='b'){
            b1--;
        }
        if(biaoji[mint][1]=='c'){
            c1--;
        }
        if(biaoji[mint][2]=='a'){
            a1++;
        }
        if(biaoji[mint][2]=='b'){
            b1++;
        }
        if(biaoji[mint][2]=='c'){
            c1++;
        }
        if(a1<=n/2&&b1<=n/2&&c1<=n/2){
            cout<<maxx<<endl;
            flag=1;
            return;
        }else{
            biaoji[mint][2]='*';
        }
    }
}
int meijv2(long long n,int s[199999][5],char biaoji[199999][5],int a1,int b1,int c1,int maxx){
    int a=a1;
    int b=b1;
    int c=c1;
    int maxxx=maxx;
    int minn=39999,mint;
    for(int j=1;j<=n;j++){
        maxx=maxxx;
        for(int i=1;i<=n;i++){
            if((s[i][1]-s[i][3])<minn&&biaoji[i][3]!='*'){
                minn=s[i][1]-s[i][3];
                mint=i;
            }
        }
        maxx=maxx-minn;
        if(biaoji[mint][1]=='a'){
            a1--;
        }
        if(biaoji[mint][1]=='b'){
            b1--;
        }
        if(biaoji[mint][1]=='c'){
            c1--;
        }
        if(biaoji[mint][3]=='a'){
            a1++;
        }
        if(biaoji[mint][3]=='b'){
            b1++;
        }
        if(biaoji[mint][3]=='c'){
            c1++;
        }
        if(a1<=n/2&&b1<=n/2&&c1<=n/2){
            return maxx;
        }else{
            biaoji[mint][3]='*';
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    long long n;
    cin>>t;
    for(int i=1;i<=t;i++){
        flag=0;
        int a,b,c,a1=0,b1=0,c1=0,s[199999][5],maxx=0;
        char biaoji[199999][5];
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a>>b>>c;
            if(a<=b&&b<=c){
                    c1++;
                    maxx+=c;
                    s[j][1]=c;
                    biaoji[j][1]='c';
                    s[j][2]=b;
                    biaoji[j][2]='b';
                    s[j][3]=a;
                    biaoji[j][3]='a';
            }else if(a<=c&&c<=b){
                    b1++;
                    maxx+=b;
                    s[j][1]=b;
                    biaoji[j][1]='b';
                    s[j][2]=c;
                    biaoji[j][2]='c';
                    s[j][3]=a;
                    biaoji[j][3]='a';
            }else if(b<=a&&a<=c){
                    c1++;
                    maxx+=c;
                    s[j][1]=c;
                    biaoji[j][1]='c';
                    s[j][2]=a;
                    biaoji[j][2]='a';
                    s[j][3]=b;
                    biaoji[j][3]='b';
            }else if(b<=c&&c<=a){
                    a1++;
                    maxx+=a;
                    s[j][1]=a;
                    biaoji[j][1]='a';
                    s[j][2]=c;
                    biaoji[j][2]='c';
                    s[j][3]=b;
                    biaoji[j][3]='b';
            }else if(c<=a&&a<=b){
                    b1++;
                    maxx+=b;
                    s[j][1]=b;
                    biaoji[j][1]='b';
                    s[j][2]=a;
                    biaoji[j][2]='a';
                    s[j][3]=c;
                    biaoji[j][3]='c';
            }else if(c<=b&&b<=a){
                    a1++;
                    maxx+=a;
                    s[j][1]=a;
                    biaoji[j][1]='a';
                    s[j][2]=b;
                    biaoji[j][2]='b';
                    s[j][3]=c;
                    biaoji[j][3]='c';
            }
        }
        if(a1<=n/2&&b1<=n/2&&c1<=n/2){
            cout<<maxx<<endl;
        }else{
            meijv1(n,s,biaoji,a1,b1,c1,maxx);
            if(flag=0){
                meijv2(n,s,biaoji,a1,b1,c1,maxx);
            }
        }
    }
    return 0;
}
