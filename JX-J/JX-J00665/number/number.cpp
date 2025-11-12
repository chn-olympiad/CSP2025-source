#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    char s[1000000]={'a'};
    int a[1000000];
    char b[1000000]={'a'};
    cin>>s;
    for(int i=0;i<1000000;i++){
        a[i]=s[i];
        if(a[i]>47&&a[i]<58){
            b[i]=s[i];
        }
    }
    for(int i=1;i<1000000;i++){
        a[i-1]=b[i];
    }
    for(int i=0;i<1000000;i++){
        while(a[i]<a[i+1]){
            if(a[i]<a[i+1]){
                int m;
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    for(int i=0;i<1000000;i++){
        while(a[i]<a[i+1]){
            if(a[i]<a[i+1]){
                int m;
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    for(int i=0;i<1000000;i++){
        while(a[i]<a[i+1]){
            if(a[i]<a[i+1]){
                int m;
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    for(int i=0;i<1000000;i++){
        while(a[i]<a[i+1]){
            if(a[i]<a[i+1]){
                int m;
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    for(int i=0;i<1000000;i++){
        while(a[i]<a[i+1]){
            if(a[i]<a[i+1]){
                int m;
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    for(int i=0;i<1000000;i++){
        while(a[i]<a[i+1]){
            if(a[i]<a[i+1]){
                int m;
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    for(int i=0;i<1000000;i++){
        while(a[i]<a[i+1]){
            if(a[i]<a[i+1]){
                int m;
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    for(int i=0;i<1000000;i++){
        while(a[i]<a[i+1]){
            if(a[i]<a[i+1]){
                int m;
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    for(int i=0;i<1000000;i++){
        while(a[i]<a[i+1]){
            if(a[i]<a[i+1]){
                int m;
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    for(int i=0;i<1000000;i++){
        while(a[i]<a[i+1]){
            if(a[i]<a[i+1]){
                int m;
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    for(int i=0;i<1000000;i++){
        while(a[i]<a[i+1]){
            if(a[i]<a[i+1]){
                int m;
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    for(int i=0;i<1000000;i++){
        while(a[i]<a[i+1]){
            if(a[i]<a[i+1]){
                int m;
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    for(int i=0;i<1000000;i++){
        while(a[i]<a[i+1]){
            if(a[i]<a[i+1]){
                int m;
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    for(int i=0;i<1000000;i++){
        while(a[i]<a[i+1]){
            if(a[i]<a[i+1]){
                int m;
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    for(int i=0;i<1000000;i++){
        while(a[i]<a[i+1]){
            if(a[i]<a[i+1]){
                int m;
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    for(int i=0;i<1000000;i++){
        while(a[i]<a[i+1]){
            if(a[i]<a[i+1]){
                int m;
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    for(int i=1;i<1000000;i++){
        b[i]=a[i-1];
        cout<<b[i];
    }
}
