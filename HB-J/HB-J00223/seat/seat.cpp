#include<bits/stdc++.h>
using namespace std;
int n,m,l=1,h=1;
int student[1000]={};
int s=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;++i){
        scanf("%d",&student[i]);
    }
    s=student[1];
    sort(student+1,student+1+n*m,cmp);
    int h=1,ans=1;
    while(l<=m){
        if(student[ans]==s){
            cout<<l<<" "<<h;
            break;
        }
        else{
            if(h<n&&l%2==1){
                ++h;
                ++ans;
            }
            else if(h>1&&l%2==0){
                h--;
                ++ans;
            }
            else{
                ++l;
                ++ans;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
