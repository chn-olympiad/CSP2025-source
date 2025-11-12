#include <bits/stdc++.h>
using namespace std;

int chengji[110];
int main(){

freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int n,m;
int rscore,rn,rm;
cin>>n>>m;
for(int i=1;i<=n*m;i++){
    cin>>chengji[i];
}
    rscore=chengji[1];

sort(chengji+1,chengji+n*m+1);
for(int i=1;i<=n*m;i++){
        if(chengji[i]==rscore){
            int s=n*m-i+1;
            if(s%n==0)rm=s/n;
            else rm=s/n+1;
            if(rm%2==1){
                rn=s-n*(rm-1);
            }else if(rm%2==0){
                rn=n-(s-n*(rm-1))+1;
            }
        break;
        }

}
cout<<rn<<" "<<rm;
return 0;
}
