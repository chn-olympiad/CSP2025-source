#include <bits/stdc++.h>
using namespace std;
//FILE *f1=fopen("road.in",r) *f2=fopen("road.out",w);
int n,m,k,cnt,a[12][10008],x,y,w,c[20],d[10008],come[10008],ans,p[10008];
bool is[10008];
vector<pair<int,int> >v[10008];
int f(int x){
    if(p[x]==0){
        return x;
    }
    return p[x]=x;
}
void prim(int f){
    //cout<<f<<endl<<cnt<<endl;
    d[f]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >p;
    p.push(make_pair(0,f));
    //cout<<cnt<<endl<<n<<endl;
    while(cnt<n){
            //cout<<111111111111111111111111<<endl;
        int y=p.top().first;
        int x=p.top().second;
    //cout<<x<<endl;
        p.pop();
        if(is[x]){
            continue;
        }
        is[x]=1;
        cnt++;
        if(x<=n){
            ans+=y-come[x];
        }
        for(int i=0;i<v[x].size();i++){
            int z=v[x][i].first;
            if(is[z]){
                continue;
            }
            if(z>n){
                if(y+v[x][i].second+c[z-n]<d[z]){
                    d[z]=y+v[x][i].second+c[z-n];
                    p.push(make_pair(d[z],z));
                    come[z]=y;
                }
                continue;
            }
            if(y+v[x][i].second<d[z]){
                d[z]=y+v[x][i].second;
                p.push(make_pair(d[z],z));
                come[z]=y;
                if(x>n){
                    come[z]=come[x];
                }
            }
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
//cout<<1<<endl;
    cin>>n>>m>>k;
    //cout<<n<<endl<<m<<endl<<k<<endl;
    //fscanf(f1,"%d%d%d",n,m,k);
    for(int i=1;i<=m;i++){
            cin>>x>>y>>w;
        //fscanf(f1,"%d%d%d",x,y,w);
        v[x].push_back(make_pair(y,w));
        v[y].push_back(make_pair(x,w));
    }
    for(int i=1;i<=k;i++){
            cin>>c[i];
        for(int j=1;j<=n;j++){
            //fscanf(f1,"%d",a[i][j]);
            cin>>a[i][j];
            v[i+n].push_back(make_pair(a[i][j],j));
            v[j].push_back(make_pair(a[i][j],i+n));
        }
    }
    prim(1);
    cout<<ans<<endl;
    //sort(s+1,s+z+1,cmp);
    //for(int i=1;i<=z;i++){
     //   if(cnt1==0){
    //        cout<<ans<<endl;
    //        return 0;
    //    }
    //    int ra=f(s[i].x);
     ///   int rb=f(s[i].y);
      //  if(ra==rb){
     ///       continue;
     //   }
      //  if(s[i].x<=n&&s[i].y<=n){
      //      cnt1--;
      //      p[ra]=rb;
      //      ans+=s[i].w;
     // ///  }else{
     //       cnt2--;
       //     if(ra==s[i].x){
       //         p[ra]=rb;
      //          s[i].w+=c[s[i].x];
      //          ans+=c[s[i].x];
      ////      }else{
      //          cnt1--;
      //          ans+=s[i].w;
      ///          ans+=[s[i].x][ra];
      //          p[ra]=rb;
      //      }
      //  }
    //}
    return 0;
}
