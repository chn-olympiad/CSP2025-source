#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,f=0,v=0,cnt;
    cin>>n>>m;
    string s;
    int a[15],q[15];
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>q[i];
    }
    if(n==1){
        if(s[0]==1&&m==1) cout<<1;
        else cout<<0;
    }
    else if(n==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n&&j!=i;j++){
                a[1]=i;
                a[2]=j;
                for(int z=1;z<=n;z++){
                    if(s[i-1]=='1'&&q[i]>=f) v++;
                    else f++;
                }
                if(v>=m) cnt++;
            }
        }
        cout<<cnt;
    }
    else if(n==3){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n&&j!=i;j++){
                for(int b=1;b<=n&&b!=j;b++){
                                    a[1]=i;
                a[2]=j;
                a[3]=b;
                for(int z=1;z<=n;z++){
                    if(s[i-1]=='1'&&q[i]>=f) v++;
                    else f++;
                }
                if(v>=m) cnt++;
                }
            }
        }
        cout<<cnt;
    }
    else if(n==4){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n&&j!=i;j++){
                for(int b=1;b<=n&&b!=j;b++){
                    for(int c=1;c<=n&&c!=b;c++){
                                                            a[1]=i;
                a[2]=j;
                a[3]=b;
                a[4]=c;
                for(int z=1;z<=n;z++){
                    if(s[i-1]=='1'&&q[i]>=f) v++;
                    else f++;
                }
                if(v>=m) cnt++;
                    }
                }
            }
        }
        cout<<cnt;
    }
        else if(n==5){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n&&j!=i;j++){
                for(int b=1;b<=n&&b!=j;b++){
                    for(int c=1;c<=n&&c!=b;c++){
                            for(int d=1;d<=n&&d!=c;d++){
                                                                                            a[1]=i;
                a[2]=j;
                a[3]=b;
                a[4]=c;
                a[5]=d;
                for(int z=1;z<=n;z++){
                    if(s[i-1]=='1'&&q[i]>=f) v++;
                    else f++;
                }
                if(v>=m) cnt++;
                            }
                    }
                }
            }
        }
        cout<<cnt;
    }
            else if(n==6){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n&&j!=i;j++){
                for(int b=1;b<=n&&b!=j;b++){
                    for(int c=1;c<=n&&c!=b;c++){
                            for(int d=1;d<=n&&d!=c;d++){
                                    for(int e=1;e<=n&&e!=d;e++){
                                                                                                                                    a[1]=i;
                a[2]=j;
                a[3]=b;
                a[4]=c;
                a[5]=d;
                a[6]=e;
                for(int z=1;z<=n;z++){
                    if(s[i-1]=='1'&&q[i]>=f) v++;
                    else f++;
                }
                if(v>=m) cnt++;
                                    }
                            }
                    }
                }
            }
        }
        cout<<cnt;
    }
                else if(n==7){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n&&j!=i;j++){
                for(int b=1;b<=n&&b!=j;b++){
                    for(int c=1;c<=n&&c!=b;c++){
                            for(int d=1;d<=n&&d!=c;d++){
                                    for(int e=1;e<=n&&e!=d;e++){
                                            for(int f=1;f<=n&&f!=e;f++){
                                                                                                                                                                                    a[1]=i;
                a[2]=j;
                a[3]=b;
                a[4]=c;
                a[5]=d;
                a[6]=e;
                a[7]=f;
                for(int z=1;z<=n;z++){
                    if(s[i-1]=='1'&&q[i]>=f) v++;
                    else f++;
                }
                if(v>=m) cnt++;
                                            }
                                    }
                            }
                    }
                }
            }
        }
        cout<<cnt;
    }
                   else if(n==8){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n&&j!=i;j++){
                for(int b=1;b<=n&&b!=j;b++){
                    for(int c=1;c<=n&&c!=b;c++){
                            for(int d=1;d<=n&&d!=c;d++){
                                    for(int e=1;e<=n&&e!=d;e++){
                                            for(int f=1;f<=n&&f!=e;f++){
                                                    for(int l=1;l<=n&&l!=f;l++){
                                                                                                                                                                                                                                            a[1]=i;
                a[2]=j;
                a[3]=b;
                a[4]=c;
                a[5]=d;
                a[6]=e;
                a[7]=f;
                a[8]=l;
                for(int z=1;z<=n;z++){
                    if(s[i-1]=='1'&&q[i]>=f) v++;
                    else f++;
                }
                if(v>=m) cnt++;
                                                    }
                                            }
                                    }
                            }
                    }
                }
            }
        }
        cout<<cnt;
    }
                       else if(n==9){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n&&j!=i;j++){
                for(int b=1;b<=n&&b!=j;b++){
                    for(int c=1;c<=n&&c!=b;c++){
                            for(int d=1;d<=n&&d!=c;d++){
                                    for(int e=1;e<=n&&e!=d;e++){
                                            for(int f=1;f<=n&&f!=e;f++){
                                                    for(int l=1;l<=n&&l!=f;l++){
                                                            for(int o=1;o<=n&&o!=l;o++){
                                                                                                                                                                                                                                                                                                            a[1]=i;
                a[2]=j;
                a[3]=b;
                a[4]=c;
                a[5]=d;
                a[6]=e;
                a[7]=f;
                a[8]=l;
                a[9]=o;
                for(int z=1;z<=n;z++){
                    if(s[i-1]=='1'&&q[i]>=f) v++;
                    else f++;
                }
                if(v>=m) cnt++;
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                }
            }
        }
        cout<<cnt;
    }
                           else if(n==10){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n&&j!=i;j++){
                for(int b=1;b<=n&&b!=j;b++){
                    for(int c=1;c<=n&&c!=b;c++){
                            for(int d=1;d<=n&&d!=c;d++){
                                    for(int e=1;e<=n&&e!=d;e++){
                                            for(int f=1;f<=n&&f!=e;f++){
                                                    for(int l=1;l<=n&&l!=f;l++){
                                                            for(int o=1;o<=n&&o!=l;o++){
                                                                    for(int p=1;p<=n&&p!=o;p++){
                                                                                                                                                                                                                                                                                                                                                                                    a[1]=i;
                a[2]=j;
                a[3]=b;
                a[4]=c;
                a[5]=d;
                a[6]=e;
                a[7]=f;
                a[8]=l;
                a[9]=o;
                a[10]=p;
                for(int z=1;z<=n;z++){
                    if(s[i-1]=='1'&&q[i]>=f) v++;
                    else f++;
                }
                if(v>=m) cnt++;
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                }
            }
        }
        cout<<cnt;
    }
    return 0;
}
