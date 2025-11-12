#include<bits/stdc++.h>
using namespace std;
int l[1007];
int b[1007][50];
int n,a[1007];
int c[50],t,s,o;
void get2(int m,int num){
    int x=m;
    for(int i=1;x;i++){
        b[num][i]=x%2;
        x/=2;
        l[num]++;
    }
    for(int i=l[num];l[num]>1;i--){
        if(b[num][i]==0){
            l[num]--;
        }
        else{
            break;
        }
    }
    if(l[num]==0)l[num]++;
    for(int i=1;i<=l[num]/2;i++){
        swap(b[num][i],b[num][l[num]-i+1]);
    }
}
void getchange(int j){
    for(int i=t,bi=l[j];i>=1;i--,bi--){
        if(bi<1){break;}
        //cout<<"G:c="<<c[i]<<" "<<"b="<<b[j][bi]<<" /";
        if(c[i]==1||b[j][bi]==1){c[i]=1;}
        else{c[i]=0;}
    }
    if(t==0)t++;
}
bool f(){
    string ss;
    for(int i=1;i<=t;i++){
        ss+=c[i]-'0';
    }
    int lo=0;
    string ss2;
    while(o){
        ss2+=(o%2)-'0';
        o/=2;
        lo++;
    }
    for(int i=1;i<=lo/2;i++){
        swap(ss2[i],ss2[lo-i+1]);
    }
    for(int i=lo;i>1;i--){
        if(ss2[i]=='0'){
            lo--;
        }
    }
    if(!lo){
        lo++;
    }
    if(ss==ss2){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>o;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        get2(a[i],i);
    }
    for(int i=1;i<=n;i++){
        bool ff=0;
        t=l[i];
        //for(int j=i;j<=l[i];j++){
            //c[j]=b[i][j];
            //cout<<c[j];
        //}
        //cout<<" //";
        for(int j=i+1;j<=n;j++){
            t=max(t,l[j]);
            //cout<<"t="<<t;
            getchange(j);
            //cout<<"c=";
            //for(int o=1;o<=t;o++){
            //    cout<<c[o];
            //}
            //cout<<" ";

            if(f()&&!ff){
                ff=1;
                s++;
                i=i+j-1;
            }

        }
        //cout<<endl;

    }
    cout<<s;
    return 0;
}
