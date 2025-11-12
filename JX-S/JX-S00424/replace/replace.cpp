#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
string a[N][2];
string t1,t2;
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    for(int i=0;i<q;i++){
        cin>>t1>>t2;
        int t=0;
        for(int j=0;j<n;j++){
            int id=0;
            string tmp;
            while(id < (int)t1.size()){
                id=(int)t1.find(a[j][0],id);
                if(id==-1)
                    break;
                tmp=t1;
                if(tmp.replace(id,a[j][0].size(),a[j][1])==t2)
                    t++;
                id++;
            }
        }
        printf("%d\n",t);
    }
    return 0;
}
