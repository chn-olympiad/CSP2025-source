#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+5;

struct needR{
    vector<int> openNeed;
};

int n,m,k;
int r[N][N];
map<pair<int,int>,needR> needf;

bool visited[N];
vector<int> row;
void dfs(int start,int now,int sum){
    if(sum < r[min(start,now)][max(start,now)]){
        r[min(start,now)][max(start,now)] = sum;
        needf[make_pair(min(start,now),max(start,now))].openNeed = row;
    }else if(sum == r[min(start,now)][max(start,now)] && row.size() > needf[make_pair(min(start,now),max(start,now))].openNeed.size()){
        r[min(start,now)][max(start,now)] = sum;
        needf[make_pair(min(start,now),max(start,now))].openNeed = row;
    }
    for(int i=0;i<n;i++){
        if(i != now && visited[i] == false){
            row.push_back(i);
            visited[i] = true;
            dfs(start,i,sum + r[min(i,now)][max(i,now)]);
            row.pop_back();
            visited[i] = false;
        }
    }
}

int last;
int getDFS(int sum,int now){
    if(last <= 0){
        return sum;
    }
    int re = -1;
    for(int i=0;i<n;i++){
        if(i != now && visited[i] == false){
            int la = 0;
            int copy_visited[N];
            for(int j=0;j<n;j++){
                copy_visited[j] = visited[j];
            }
            for(int j=0;j<needf[make_pair(min(i,now),max(i,now))].openNeed.size();j++){
                if(visited[needf[make_pair(min(i,now),max(i,now))].openNeed[j]] == false){
                    la++;
                    visited[needf[make_pair(min(i,now),max(i,now))].openNeed[j]] = true;
                }
            }
            visited[i] = true;
            last -= la;
            int ansr = getDFS(sum + r[min(i,now)][max(i,now)],i);
            last += la;
            visited[i] = false;
            for(int j=0;j<n;j++){
                visited[j] = copy_visited[j];
            }
            if(re == -1 || ansr < re){
                re = ansr;
            }
        }
    }
    return re;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    memset(r,-1,sizeof(r[0])*n);
    for(int i=0;i<m;i++){
        int c1,c2,w;
        cin>>c1>>c2>>w;
        c1--;
        c2--;
        r[min(c1,c2)][max(c1,c2)] = w;
        needf[make_pair(min(c1,c2),max(c1,c2))].openNeed.push_back(c1);
        needf[make_pair(min(c1,c2),max(c1,c2))].openNeed.push_back(c2);
    }

    memset(visited,false,sizeof(visited[0])*n);

    int updateCity[N];

    for(int i=0;i<k;i++){
        int c;
        cin>>c;
        for(int j=0;j<n;j++){
            cin>>updateCity[j];
            for(int k=0;k<j;k++){
                if(r[k][j] == -1){
                    r[k][j] = updateCity[k]+updateCity[j]+c;
                }else{
                    r[k][j] = min(r[k][j],updateCity[k]+updateCity[j]+c);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        visited[i] = true;
        row.push_back(i);
        dfs(i,i,0);
        visited[i] = false;
        row.pop_back();
    }

    last = n - 1;
    int ans = -1;
    for(int i=0;i<n;i++){
        visited[i] = true;
        int re = getDFS(0,i);
        visited[i] = false;
        if(ans == -1 || re < ans){
            ans = re;
        }
    }
    cout<<ans;

    return 0;
}
