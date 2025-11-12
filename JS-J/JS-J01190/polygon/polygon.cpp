#include <bits/stdc++.h>
using namespace std;
int bubblesort(int length,int a[]){
    for(int i=1;i<=length;i++)
        for(int j=1;j<=length-i;j++)
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
}
int b[11]={0,9,3,6,7,1,4};
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n=6,s=0;
    //cin>>n;
    for(int i=1;i<=n;i++)
        //cin>>b[i];
    bubblesort(n,b);
    if(n<3)
        cout<<0;
    else if(n>=3){
        if(b[1]+b[2]>b[3])
            s++;
        if(n>=4){
            if(b[1]+b[2]>b[4])
                s++;
            if(b[1]+b[2]+b[3]>b[4])
                s++;
            if(b[1]+b[3]>b[4])
                s++;
            if(b[2]+b[3]>b[4])
                s++;
            if(n>=5){
                for(int i=2;i<=4;i++)
                    if(b[1]+b[i]>b[5])
                        s++;
                for(int i=3;i<=4;i++)
                    if(b[2]+b[i]>b[5])
                        s++;
                if(b[3]+b[4]>b[5])
                    s++;
                if(b[1]+b[2]+b[3]>b[5])
                    s++;
                if(b[1]+b[2]+b[4]>b[5])
                    s++;
                if(b[2]+b[3]+b[4]>b[5])
                    s++;
                if(b[1]+b[4]+b[3]>b[5])
                    s++;
                if(b[1]+b[2]+b[3]+b[4]>b[5])
                    s++;
                if(n>=6){
                    for(int i=2;i<=5;i++)
                        if(b[1]+b[i]>b[6])
                            s++;
                    for(int i=3;i<=5;i++)
                        if(b[2]+b[i]>b[6])
                            s++;
                    if(b[3]+b[4]>b[6])
                        s++;
                    if(b[3]+b[5]>b[6])
                        s++;
                    if(b[4]+b[5]>b[6])
                        s++;
                    for(int i=3;i<=5;i++)
                        if(b[1]+b[2]+b[i]>b[6])
                            s++;
                    if(b[1]+b[4]+b[3]>b[6])
                        s++;
                    if(b[1]+b[5]+b[3]>b[6])
                        s++;
                    if(b[1]+b[4]+b[5]>b[6])
                        s++;
                    if(b[3]+b[2]+b[4]>b[6])
                        s++;
                    if(b[5]+b[2]+b[3]>b[6])
                        s++;
                    if(b[5]+b[2]+b[4]>b[6])
                        s++;
                    if(b[4]+b[5]+b[3]>b[6])
                        s++;
                    if(b[1]+b[2]+b[3]+b[4]>b[6])
                        s++;
                    if(b[1]+b[2]+b[3]+b[5]>b[6])
                        s++;
                    if(b[1]+b[5]+b[3]+b[4]>b[6])
                        s++;
                    if(b[5]+b[2]+b[3]+b[4]>b[6])
                        s++;
                    if(b[1]+b[2]+b[5]+b[4]>b[6])
                        s++;
                    if(b[1]+b[2]+b[3]+b[4]+b[5]>b[6])
                        s++;
                }
            }
        }
        cout<<s;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
