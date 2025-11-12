#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll get_a;
char get_c;
bool get_f;
inline ll getint(){
    get_a=0;
    get_c=getchar();
    get_f=0;
    while((get_c<'0'||get_c>'9')&&get_c!=EOF){
        if(get_c=='-'){
            get_f=1;
            get_c=getchar();
            break;
        }
        get_c=getchar();
    }
    while(get_c>='0'&&get_c<='9'){
        get_a=get_a*10+get_c-'0';
        get_c=getchar();
    }
    return get_f?-get_a:get_a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a1=0,a2=0;
    n=getint();
    m=getint();
    priority_queue<pair<short,short>>q;
    for(int i=1;i<=n*m;i++)
        q.push({getint(),i});
    bool flag=0;
    bool breakflag=0;
    for(int i=1;i<=m;i++){
        if(flag){
            for(int j=n;j>=1;j--){
                if(q.top().second==1){
                    a1=i;a2=j;
                    breakflag=1;
                    break;
                }
                q.pop();
            }
        }
        else{
            for(int j=1;j<=n;j++){
                if(q.top().second==1){
                    a1=i;a2=j;
                    breakflag=1;
                    break;
                }
                q.pop();
            }
        }
        if(breakflag)break;
    }
    cout<<a1<<' '<<a2<<'\n';
    return 0;
}
