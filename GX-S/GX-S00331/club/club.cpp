#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MXN 100010
#define fs first
using namespace std;
typedef pair<int,int>s;
typedef pair<int,int>t;
priority_queue<t>c[4];
int T,n,nw[MXN];
s stu[MXN][4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=3;i++){
            while(!c[i].empty())c[i].pop();
        }
        int res=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>stu[i][j].fs;
                stu[i][j].second=j;
            }
            sort(stu[i]+1,stu[i]+3+1);
            int p=stu[i][3].second;
            if(c[p].size()==n/2){
                int np=c[p].top().second;
                if(stu[np][2].fs-stu[np][3].fs+stu[i][3].fs>stu[i][2].fs){
                    c[p].pop();
                    res+=stu[np][2].fs-stu[np][3].fs+stu[i][3].fs;
                    c[p].push({stu[i][2].fs-stu[i][3].fs,i});
                }
                else{
                    res+=stu[i][2].fs;
                    c[stu[i][2].second].push({stu[i][1].fs-stu[i][2].fs,i});
                }
            }
            else {
                res+=stu[i][3].fs;
                c[p].push({stu[i][2].fs-stu[i][3].fs,i});
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
