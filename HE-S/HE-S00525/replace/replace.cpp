#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
string s1[200005],s2[200005];
string t1[200005],t2[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0; i<n; ++i){
        cin>>s1[i]>>s2[i];
    }
    for(int i=0; i<q; ++i){
        cin>>t1[i]>>t2[i];
        int cnt=0;
        for(int j=0; j<n; ++j){
            int tmp = t1[i].find(s1[j]);
            //cout<< tmp <<endl;
            if(tmp>=0){
                string temp=t1[i];
                temp.replace(tmp,s1[j].size(),s2[j]);
                //cout<<t1[i]<<" "<<temp<<endl;
                if(temp==t2[i])
                    ++cnt;
            }

        }
        printf("%d",cnt);
    }
    return 0;

}
//2 1 xabcx xacdx bc cd xabcx xacdx
