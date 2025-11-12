#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t=0; scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n=0; scanf("%d",&n);
        int r=0;
        int cl[3]={0,0,0};
        for(int j=0;j<n;j++){
            unsigned long long a=0,b=0,c=0;
            scanf("%d %d %d",&a,&b,&c);
            vector<unsigned long long> s={a,b,c};
            vector<unsigned long long> t={a,b,c};
            sort(s.begin(),s.end());
            for(int k=0;k<3;k++){
                if(t.at(k)==s.back()){
                    if(cl[k]+1>n/2){
                        s.pop_back();
                        continue;
                    }
                    cl[k]++;
                }
            }
            r=r+s.back();
        }
        printf("%d\n",r);
    }
    return 0;
}