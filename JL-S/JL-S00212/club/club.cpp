#include<bits/stdc++.h>
using namespace std;
struct club{
    int a;
    int b;
    int c;
    int ch=0;
    int t=0;
};

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int r[t];
    for(int g=0;g<t;g++){
        int n;
        cin>>n;
        club a[n];
        for(int i=0;i<n;i++){
            cin>>a[i].a;
            cin>>a[i].b;
            cin>>a[i].c;
        }
        int x=0,y=0,z=0,x1=0,y1=0,z1=0;
        int i=0;
        while(x<n/2&&i<n){
                int max1;
            for(int j=0;j<n;j++){
                if(a[j].a>max1&&a[j].a>a[j].b&&a[j].a>a[j].c){
                    max1=j;
                }else if(a[j].a>max1&&a[j].a>a[j].b) a[j].t=1;
            }
            a[max1].ch=1;
            x++;
            x1+=a[max1].a;
            i++;
        }
        i=0;
        while(y<n/2&&i<n){
                int max1;
            for(int j=0;j<n;j++){
                if(a[j].b>max1&&a[j].b>a[j].a&&a[j].b>a[j].c){
                    max1=j;
                }else if(a[j].b>max1&&a[j].b>a[j].a) a[j].t=2;
            }
            a[max1].ch=2;
            y++;
            y1+=a[max1].a;
            i++;
        }
        i=0;
        while(z<n/2&&i<n){
                int max1;
            for(int j=0;j<n;j++){
                if(a[j].c>max1&&a[j].c>a[j].a&&a[j].c>a[j].b){
                    max1=j;
                }else if(a[j].c>max1&&a[j].c>a[j].a) a[j].t=3;
            a[max1].ch=3;
            z++;
            z1+=a[max1].c;
            i++;
        }
        }
        for(int j=0;j<n;j++){
                if(a[j].ch==0){
                    if(a[j].t==1){
                        if(y>n/2){
                            a[j].ch=3;
                            z++;
                            z1+=a[j].c;
                        }else if(z>n/2){
                            a[j].ch=2;
                            y++;
                            y1+=a[j].b;
                        }else if(a[j].b>a[j].c){
                            a[j].ch=2;
                            y++;
                            y1+=a[j].b;
                        }else {
                            a[j].ch=3;
                            z++;
                            z1+=a[j].c;
                        }
                    }else if(a[j].t==2){
                        if(z>n/2){
                            a[j].ch=1;
                            x++;
                            x1+=a[j].a;
                        }else if(x>n/2){
                            a[j].ch=3;
                            z++;
                            z1+=a[j].c;
                        }else if(a[j].a>a[j].c){
                            a[j].ch=1;
                            x++;
                            x1+=a[j].a;
                        }else {
                            a[j].ch=3;
                            z++;
                            z1+=a[j].c;
                        }
                    }else if(z>n/2){
                        if(y>n/2){
                            a[j].ch=1;
                            x++;
                            x1+=a[j].a;
                        }else if(x>n/2){
                            a[j].ch=2;
                            y++;
                            y1+=a[j].b;
                        }else if(a[j].a>a[j].b){
                            a[j].ch=1;
                            x++;
                            x1+=a[j].a;
                        }else {
                            a[j].ch=2;
                            y++;
                            y1+=a[j].b;
                        }
                    }
                }
            }




        r[g]=x1+y1+z1;

    }
    for(int i=0;i<t;i++){
        cout<<r[i]<<endl;
    }
    return 0;
}
