#include<bits/stdc++.h>
using namespace std;

int ls[4],ls1[10000000],n;

int cl[100001][10];

int lss=1;
void fun(int x,int cnt){
    if(x>n){
        ls1[lss]=cnt;
        lss++;
        return;
    }
    for(int i = 1;i<=3;i++){
        ls[i]+=1;
        if(ls[i]>n/2){
            ls[i]-=1;
            continue;
        }
        fun(x+1,cnt+cl[x][i]);
        ls[i]-=1;
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t>0){
        lss=1;
        for(int i = 1;i<=n*3;i++){
            ls1[i]=0;
        }
        cin>>n;
            for(int i = 1;i<=n;i+=1){
            cin>>cl[i][1]>>cl[i][2]>>cl[i][3];
        }
        fun(1,0);
        int ma = 0;
        for(int i = 1;i<=lss;i+=1){
            ma=max(ma,ls1[i]);
        }
        cout<<ma<<endl;
        t--;
}   
    return 0;
}