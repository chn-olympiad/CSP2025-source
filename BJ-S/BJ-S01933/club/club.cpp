#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,z;
};
struct node1{
    int cha,ma1,ma2,z1,z2;
    friend bool operator<(node1 aa,node1 bb){
        return aa.cha<bb.cha;
    }
};
const int N=1e5+5;
int t,n,zu[4],maxx;
node max1[N],max2[N];
priority_queue<node1>q;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    for(int o=1;o<=t;o++){
        cin>>n;
        for(int i=1;i<=n;i++){
            int a,b,c;cin>>a>>b>>c;
            if(a>b&&a>c){
                max1[i]={1,a};
                if(b>c){max2[i]={2,b};}
                else{max2[i]={3,c};}
            }
            else if(b>a&&b>c){
                max1[i]={2,b};
                if(a>c){max2[i]={1,a};}
                else{max2[i]={3,c};}
            }
            else if(c>a&&c>b){
                max1[i]={3,c};
                if(a>b){max2[i]={1,a};}
                else {max2[i]={2,b};}
            }
            q.push({max1[i].z-max2[i].z,max1[i].z,max2[i].z,max1[i].u,max2[i].u});
        }
        while(!q.empty()){
            node1 v=q.top();q.pop();
            if(zu[v.z1]==n/2){
                zu[v.z2]++;
                maxx+=v.ma2;
            }
            else{
                zu[v.z1]++;
                maxx+=v.ma1;
            }
        }
        cout<<maxx<<endl;
        maxx=0;zu[0]=zu[1]=zu[2]=zu[3]=0;

    }
}