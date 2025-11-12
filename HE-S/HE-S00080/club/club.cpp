#include<bits/stdc++.h>
using namespace std;
struct Node{
    int x;
    int y;
    int z;
};
int t,n;
bool cmp1(Node s,Node ss){
    if(s.x==ss.x){
        return max(s.y,s.z)<max(ss.y,ss.z);
    }
    return s.x>ss.x;
}
bool ccmp1(Node s,Node ss){
    return max(s.y,s.z)>max(ss.y,ss.z);
}
bool cmp2(Node s,Node ss){
    if(s.y==ss.y){
        return max(s.x,s.z)<max(ss.x,ss.z);
    }
    return s.y>ss.y;
}
bool ccmp2(Node s,Node ss){
    return max(s.x,s.z)>max(ss.x,ss.z);
}
bool cmp3(Node s,Node ss){
    if(s.z==ss.z){
        return max(s.y,s.x)<max(ss.y,ss.x);
    }
    return s.z>ss.z;
}
bool ccmp3(Node s,Node ss){
    return max(s.x,s.y)>max(ss.y,ss.x);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        vector<Node> a;
        vector<Node> b;
        vector<Node> c;
        for(int i=1;i<=n;i++){
            int s,ss,sss;
            cin>>s>>ss>>sss;
            Node k;
            k.x=s;
            k.y=ss;
            k.z=sss;
            a.push_back(k);
            b.push_back(k);
            c.push_back(k);
        }
        int maxx=0;
        int sum1=0,sum2=0,sum3=0;
        sort(a.begin(),a.end(),cmp1);
        for(int j=0;j<n/2;j++){
            sum1+=a[j].x;
        }
        sort(a.begin()+(n/2),a.end(),ccmp1);
        for(int j=n/2;j<n;j++){
            sum1+=max(a[j].y,a[j].z);
        }
        sort(b.begin(),b.end(),cmp2);
        for(int j=0;j<n/2;j++){
            sum2+=b[j].y;
        }
        sort(b.begin()+(n/2),b.end(),ccmp2);
        for(int j=n/2;j<n;j++){
            sum2+=max(b[j].x,b[j].z);
        }
        sort(c.begin(),c.end(),cmp3);
        for(int j=0;j<n/2;j++){
            sum3+=c[j].z;
        }
        sort(c.begin()+(n/2),c.end(),ccmp3);
        for(int j=n/2;j<n;j++){
            sum3+=max(c[j].y,c[j].x);
        }
        cout<<max(sum1,max(sum2,sum3))<<endl;
    }
    return 0;
}
