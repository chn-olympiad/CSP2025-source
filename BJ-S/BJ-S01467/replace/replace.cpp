#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct node{
    string s1, s2;
    int len;
}e[N];
int cnt, n, q, l ,ans;
string q1, q2;
bool cmp(node a, node b){
    return a.len < b.len ;
}
int main(){
    freopen("replace.in" , "r" , stdin);
    freopen("replace.out" , "w" , stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>e[i].s1>>e[i].s2;
        e[i].len=e[i].s1.size();
        l=max(l, e[i].len);
    }
    sort(e+1, e+1+n, cmp);
    /*
    for(int i=1;i<=n;i++){
        cout<<e[i].s1<< " " <<e[i].s2<< " " <<e[i].len<< "\n" ;
    }
    */
    for(int i=1;i<=q;i++){
        ans=0;
        cnt=-1;
        cin>>q1>>q2;
        //cout<<q1<< " " <<q2<< "\n" ;
        while(1){
            cnt++;
            for(int k=cnt+1;k<=cnt+l&&k<=q1.size();k++){
                string x1, x2, w1, w2;
                for(int j=k;j<q1.size();j++){
                    x1+=q1[j];
                    x2+=q2[j];
                }
                if(x1!=x2)continue;
                for(int j=cnt;j<k;j++){
                    w1+=q1[j];
                    w2+=q2[j];
                }
                //cout<<w1<< " " <<w2<< "\n" ;
                for(int z=1;z<=n;z++){
                    if(e[z].len>w1.size())break;
                    if(e[z].len<w1.size())continue;
                    if(e[z].s1==w1&&e[z].s2==w2)ans++;
                }
            }
            if(q1[cnt]!=q2[cnt])break;
        }
        cout<<ans<< "\n" ;
    }
    //cout<<l;

    return 0;
}
