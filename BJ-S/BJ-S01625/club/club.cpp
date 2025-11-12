#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
priority_queue<pair<int,int>> aq,bq,cq;
//s1 4 ac
//s5 TLE 100%
//other wa/pc
int al[100005],bl[100005],cl[100005];
bool v[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(v,0,sizeof(v));
        while(!aq.empty()) aq.pop();
        while(!bq.empty()) bq.pop();
        while(!cq.empty()) cq.pop();
        for(int i=1;i<=n;i++){
            cin>>al[i]>>bl[i]>>cl[i];
            aq.push({al[i]-bl[i]-cl[i],i});
            bq.push({bl[i]-al[i]-cl[i],i});
            cq.push({cl[i]-al[i]-bl[i],i});
        }
        long long s=0;
        int an=0,bn=0,cn=0;
        for(int i=1;i<=n;i++){
            while(v[aq.top().s]) aq.pop();
            while(v[bq.top().s]) bq.pop();
            while(v[cq.top().s]) cq.pop();
            int a=aq.top().f;
            int b=bq.top().f;
            int c=cq.top().f;
            if(2*an>=n) a=INT_MIN;
            if(2*bn>=n) b=INT_MIN;
            if(2*cn>=n) c=INT_MIN;
            if(a>=b&&a>=c){
                v[aq.top().s]=true;
                s+=al[aq.top().s];
                aq.pop();
                an++;
            }
            else if(b>=a&&b>=c){
                v[bq.top().s]=true;
                s+=bl[bq.top().s];
                bq.pop();
                bn++;
            }
            else{
                v[cq.top().s]=true;
                s+=cl[cq.top().s];
                cq.pop();
                cn++;
            }
        }
        cout<<s<<'\n';
        continue;
    }
    fclose(stdin);
    fclose(stdin);
    return 0;
}
