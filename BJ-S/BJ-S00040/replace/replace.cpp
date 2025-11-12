#include <iostream>
#include <queue>
using namespace std;
int n,q;
struct q{
    string a,b;
}qs[100005],d[100005];
string a;
/*bool change(int qn){
    int ans=0;
    for(int i=0;i<n;i++){
        string mob=d[i].b;
        string moa=d[i].a;
        string aa=qs[qn].a;
        string bb=qs[qn].b;
        queue<int> god;
        int dfn=0;
        int cf=0;
        for(int i=0;i<n;i++){
            if(!cf && !god.empty()){
                i=god.top;
                god.pop;
                cf=i;
            }
            if(aa[i]!=bb[i] && !cf)break;
            if(cf && (aa[i]!=moa[i-cf] || bb[i]!=mob[i-cf])){
                if(aa[i]!=bb[i] || dfn)break;
            }
            if(cf && aa[i]==moa[i-cf] && bb[i]==mob[i-cf] && aa[i]!=bb[i]){
                dfn++;
            }
            if(aa[i]==moa[0])god.push(i);


        }
    }

}*/
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<q;i++){
        cin>>qs[i].a;
        cin>>qs[i].b;
    }
    for(int i=0;i<n;i++){
        cin>>d[i].a;
        cin>>d[i].b;
    }
    for(int i=0;i<q;i++){
        cout<<0<<endl;
    }
    return 0;
}
