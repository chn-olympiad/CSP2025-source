#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
}s[100010];
int js[4][100010];
int n;
bool cmp(node x,node y){
    if(x.a!=y.a){
        return x.a>y.a;
    }else{
        return x.b>y.b;
    }
}
bool cmp1(int x,int y){
    return s[x].a>s[y].a;
}
bool cmp2(int x,int y){
    return s[x].b>s[y].b;
}
bool cmp3(int x,int y){
    return s[x].c>s[y].c;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
//        for(int i=0;i<=3;i++){
//            for(int j=0;j<100010;j++){
//                js[i][j]=0;
//            }
//        }
        memset(js,0,sizeof(js));
        cin>>n;
        int x1=0,x2=0,x3=0;
        int xc=0,xb=0,xa=0;
        for(int i=1;i<=n;i++){
            int a1,a2,a3;
            cin>>a1>>a2>>a3;
            if(a1==0)xa++;
            if(a2==0)xb++;
            if(a3==0)xc++;
            s[i].a=a1;
            s[i].b=a2;
            s[i].c=a3;
            if(a1>=a2&&a1>=a3){
                js[1][++x1]=i;
            }else if(a2>=a1&&a2>=a3){
                js[2][++x2]=i;
            }else if(a3>=a1&&a3>=a2){
                js[3][++x3]=i;
            }
//            cout<<a1<<" "<<a2<<" "<<a3<<"\n";
        }
        if(xc==n){
            if(xb==n){
                int cnt=0;
                sort(js[1]+1,js[1]+x1+1,cmp1);
                for(int i=1;i<=n/2;i++){
                    cnt+=s[js[1][i]].a;
                }
                cout<<cnt;
            }else{
                sort(s+1,s+n+1,cmp);
                int s1=0,s2=0;
                int cnt=0;
                for(int i=1;i<=n;i++){
                    if(s[i].a>=s[i].b){
                        if(s1<n/2){
                            s1++;
//                            cout<<"a"<<" "<<s[i].a<<" ";
                            cnt+=s[i].a;
                        }else{
                            s2++;
//                            cout<<"b"<<" "<<s[i].b<<" ";
                            cnt+=s[i].b;
                        }
                    }else {
                        if(s2<n/2){
                            s2++;
//                            cout<<"b"<<" "<<s[i].b<<" ";
                            cnt+=s[i].b;
                        }else{
                            s1++;
//                            cout<<"a"<<" "<<s[i].a<<" ";
                            cnt+=s[i].a;
                        }
                    }
                }
                cout<<cnt;
            }
            continue;
        }
        int cnt=0;
        if(!(x1>n/2||x2>n/2||x3>n/2)){
            for(int i=1;i<=x1;i++){
                cnt+=s[js[1][i]].a;
            }
//            cout<<cnt<<" ";
            for(int i=1;i<=x2;i++){
                cnt+=s[js[2][i]].b;
            }
//            cout<<cnt<<" ";
            for(int i=1;i<=x3;i++){
                cnt+=s[js[3][i]].c;
            }
            cout<<cnt<<"\n";
        }else{
            if(x1>n/2){
                sort(js[1]+1,js[1]+x1+1,cmp1);
                for(int i=n/2+1;i<=x1;i++){
                    int x=js[1][i];
                    if(s[x].b>=s[x].c&&x2<n/2){
                        js[2][++x2]=x;
                    }else{
                        js[3][++x3]=x;
                    }
                }
                x1=n/2;
            }else if(x2>n/2){
                sort(js[2]+1,js[2]+x2+1,cmp2);
                for(int i=n/2+1;i<=x2;i++){
                    int x=js[2][i];
                    if(s[x].a>=s[x].c&&x1<n/2){
                        js[1][++x1]=x;
                    }else{
                        js[3][++x3]=x;
                    }
                }
                x2=n/2;
            }else if(x3>n/2){
                sort(js[3]+1,js[3]+x3+1,cmp3);
                for(int i=n/2+1;i<=x3;i++){
                    int x=js[3][i];
                    if(s[x].a>=s[x].b&&x1<n/2){
                        js[1][++x1]=x;
                    }else{
                        js[2][++x2]=x;
                    }
                }
                x3=n/2;
            }

            for(int i=1;i<=x1;i++){
                cnt+=s[js[1][i]].a;
            }
//            cout<<cnt<<" ";
            for(int i=1;i<=x2;i++){
                cnt+=s[js[2][i]].b;
            }
//            cout<<cnt<<" ";
            for(int i=1;i<=x3;i++){
                cnt+=s[js[3][i]].c;
            }
            cout<<cnt<<"\n";
        }

    }
    return 0;
}
