#include<bits/stdc++.h>
using namespace std;
int n,m,d,e,f;
vector<int> a,b,c;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&n);
    while(n>0){
        scanf("%d",&m);
        int t1=0,t2=0,t3=0;
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&t1,&t2,&t3);
            a.push_back(t1);
            b.push_back(t2);
            c.push_back(t3);
        }
        for(int i=0;i<m/2;i++){
            d+=*max_element(a.begin(),a.begin()+m);
            a.erase(max_element(a.begin(),a.end()));
            e+=*max_element(b.begin(),b.begin()+m);
            b.erase(max_element(b.begin(),b.end()));
            f+=*max_element(c.begin(),c.begin()+m);
            c.erase(max_element(c.begin(),c.end()));
        }
        cout<<d+e+f<<"\n";
        n--;
    }
    return 0;
}
