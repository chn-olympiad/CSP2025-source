#include<bits/stdc++.h>
using namespace std;
long long a[10][10],g,s,g1,s1,cnt,t[10],q[10];
bool k,win;
void kai(long long x){
    for(int i=1;i<5;i++){
        for(int j=1;j<7;j++){
            if(a[i][j]==s) g--;
            cout<<a[i][j]<<" ";
        }cout<<"\n";
    }cout<<endl;
    if(g>0) cout<<x<<" win!\n",q[x]+=g+1,q[(x+2)%4+1]-=g+1;
    else cout<<x<<" lose!\n",q[x]+=g-1,q[(x+2)%4+1]-=g-1;
    for(int i=1;i<5;i++) cout<<q[i]<<" ";
    cout<<"\n\n\n";
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    srand(time(0));
    while(1){
        for(int i=1;i<5;i++) for(int j=1;j<7;j++) a[i][j]=rand()%6+1;
        for(int i=1;i<5;i++){
            win=1;
            for(int j=1;j<5;j++) if(j!=i&&q[j]>=0) win=0;
            if(win) cout<<"Congraduation!!!"<<i<<"win!!!!!";
        }if(win) break;
        for(int i=1;i<7;i++) cout<<a[1][i]<<" ";
        for(int cnt=1;;cnt++){
            cout<<"\n\nRound "<<cnt<<"\n\n1:";
            k=0;
            cin>>g1>>s1;
            if(cnt>1) cin>>k;
            if(k){
                kai(1);
                break;
            }g=g1,s=s1;
            bool flag=0;
            for(int i=2;i<5;i++){
                cout<<i<<":";
                long long cnt=0,maxn=0,maxj;
                for(int j=1;j<7;j++) if(a[i][j]==s) cnt++;
                if(g-cnt>=5){
                    cout<<"1\n\n";
                    kai(i);
                    flag=1;
                }if(flag) break;
                if(g-2<cnt) cout<<cnt+2<<" "<<s<<endl,g=cnt+2;
                else{
                    for(int j=1;j<7;j++) t[j]=0;
                    for(int j=1;j<7;j++) t[a[i][j]]++;
                    for(int j=1;j<7;j++) if(t[a[i][j]]>maxn&&a[i][j]!=s) maxn=t[a[i][j]],maxj=a[i][j];
                    g=maxn+rand()%3+2,s=maxj;
                    cout<<g<<" "<<s<<endl;
                }
            }if(flag) break;
        }
    }
    return 0;
}
