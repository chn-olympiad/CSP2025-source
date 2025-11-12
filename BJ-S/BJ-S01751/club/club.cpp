#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int T,n;
int ans=0;
struct peo{
    int x;
    int y;
    int z;
}b[100090];

void bfs(string s,int c1,int c2,int c3){
    if(c1>n/2||c2>n/2||c3>n/2){
        return;
    }
    if(s.size()!=n){
        bfs(s+"1",c1+1,c2,c3);
        bfs(s+"2",c1,c2+1,c3);
        bfs(s+"3",c1,c2,c3+1);
        return;
    }
    int sum=0;
    for(int i = 0;i <= n-1;i++){
        if(s[i]=='1'){
            sum+=b[i+1].x;
        }
        if(s[i]=='2'){
            sum+=b[i+1].y;
        }
        if(s[i]=='3'){
            sum+=b[i+1].z;
        }
    }
    ans=max(ans,sum);
    return;
}

bool cmp(peo p,peo q){
    return p.x>q.x;
}
bool cmp2(peo p,peo q){
    return p.x-p.y>q.x-q.y;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n;
        ans=0;
        bool f1=0,f2=0;
        for(int i = 1;i <= n;i++){
            cin >> b[i].x >> b[i].y >> b[i].z;
            if(b[i].y!=0){
                f1=1;
            }
            if(b[i].z!=0){
                f2=1;
            }
        }
        if(f1==0&&f2==0){
            sort(b+1,b+n+1,cmp);
            for(int i = 1;i <= n/2;i++){
                ans+=b[i].x;
            }
            cout << ans << endl;
            continue;
        }
        if(f1==0){
            for(int i = 1;i <= n;i++){
                ans+=b[i].x;
            }
            sort(b+1,b+n+1,cmp2);
            for(int i = 1;i <= n;i++){
                ans+=b[i].y-b[i].x;
            }
            continue;
        }
        bfs("",0,0,0);
        cout << ans << endl;
    }
    return 0;
}
