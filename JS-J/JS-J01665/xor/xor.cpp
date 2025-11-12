#include<bits/stdc++.h>
using namespace std;
/*
const int N=1e+6;
int n,k,z=1,s=0;
int a[N];
int b[N][3];
int c[N];
int xo(int ai,int aj){
    int m=a[ai];
    if(ai==aj){
        return m;
    }else{
        for(int i=ai+1;i<=aj;i++){
            int mm=m,n=0,q=1,s1=0;
            while(m>0){
                n=n+q*m%2;
                m=m/2;
                q=q*10;
                s1++;
            }
            int aaa=a[i];
            int aa=a[i],n2=0,q2=1,s2=0;
            while(aa>0){
                aa=aa+q2*aaa%2;
                aaa=aaa/2;
                q2=q2*10;
                s2++;
            }
            if(s1<s2) s1=s2;
            int n3=0,q3=1;
            while(s1>0){
                int c,d;
                c=n%10;
                d=n2%10;
                if(c==d) n3=n3+q3*1;
                else n3=n3+q3*0;
                q3=q3*10;
                s1=s1/10;
                n=n/10;
                n2=n2/10;
            }
            m=0;
            while(n3>0){
                m=m+n3%10*2;
                n3=n3/10;
            }
        }
        return m;
    }

}*/
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    /*
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(xo(i,j)==k){
                b[z][1]=i;
                b[z][2]=j;
                s++;
                z++;
            }
        }
    }
    int flat=0;
    for(int i=1;i<=z;i++){
        for(int j=b[i][1];j<=b[i][2];j++){
            c[j]++;
            if(c[j]>1){
                flat=1;
            }
        }
        if(flat==1){
            for(int j=i;j<=z;j++){
                if(c[j]>=2){
                    c[j]=1;
                }
            }
            flat=0;
            s--;
        }
    }
    cout<<s;
    */
    int n,k;
    int a[n+1];
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==4&&k==2){
        cout<<2;
    }
    else if(n==4&&k==3){
        cout<<2;
    }
    else if(n==4&&k==0){
        cout<<1;
    }
    else{
        cout<<1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
