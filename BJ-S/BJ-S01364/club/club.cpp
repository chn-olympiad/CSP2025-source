#include<bits/stdc++.h>
using namespace std;
multiset<int> s1,s2,s3;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int k=1;k<=t;k++){
        s1.clear();
        s2.clear();
        s3.clear();
        int n,t1=0,t2=0,t3=0,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x,y,z,maxn=0,tmp=0;
            cin>>x>>y>>z;
            maxn=max({x,y,z});
            sum+=maxn;
            if(maxn==x){
                tmp=x-max(y,z);
                if(t1<n/2){
                    s1.insert(tmp);
                    t1++;
                }else{
                    int s=*s1.begin();
                    if(tmp<s){
                        sum-=tmp;
                    }else if(tmp>s){
                        sum-=s;
                        s1.erase(s1.begin());
                        s1.insert(tmp);
                    }
                }
            }else if(maxn==y){
                tmp=y-max(x,z);
                if(t2<n/2){
                    s2.insert(tmp);
                    t2++;
                }else{
                    int s=*s2.begin();
                    if(tmp<s){
                        sum-=tmp;
                    }else if(tmp>s){
                        sum-=s;
                        s2.erase(s2.begin());
                        s2.insert(tmp);
                    }
                }
            }else{
                tmp=z-max(x,y);
                if(t3<n/2){
                    s3.insert(tmp);
                    t3++;
                }else{
                    int s=*s3.begin();
                    if(tmp<s){
                        sum-=tmp;
                    }else if(tmp>s){
                        sum-=s;
                        s3.erase(s3.begin());
                        s3.insert(tmp);
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}