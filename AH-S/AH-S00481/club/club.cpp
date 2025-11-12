#include<bits/stdc++.h>
using namespace std;
int t;
int n;
long long m;
struct node{
    int xb;
    int j1,j2,j3;
    int p,h;
    int s1,s2;
};
int vis[100010][3];
node a[100010];
int mxx1(int a,int b,int c){
    if(a>=b&&a>=c){
        return 1;
    }else if(b>=a&&b>=c){
        return 2;
    }else{
        return 3;
    }
}
int mxx2(int a,int b,int c){
    if(a>=b&&a>=c){
        return a;
    }else if(b>=a&&b>=c){
        return b;
    }else{
        return c;
    }
}
bool cmp1(int x,int y){
    if(a[x].h!=a[y].h){
        return a[x].h>a[y].h;
    }
    return a[x].j1+a[x].j2+a[x].j3>a[y].j1+a[y].j2+a[y].j3;
}
bool cmp2(int x,int y){
    if(a[x].s1!=a[y].s1){
        return a[x].s1>a[y].s1;
    }else{
        return a[x].s2>a[y].s2;
    }
}
vector<int> v;
vector<int> s[4];
void cr(int d){
 //   cout<<"xb"<<s[d].back()<<endl;
    int bh=s[d].back();
    int zxs;
    if(d==1){
        if(a[bh].j2>=a[bh].j3&&vis[bh][2]==0){
            zxs=2;
        }else{
            zxs=3;
        }
    }
    if(d==2){
        if(a[bh].j1>=a[bh].j3&&vis[bh][1]==0){
            zxs=1;
        }else{
            zxs=3;
        }
    }
    if(d==3){
        if(a[bh].j1>=a[bh].j2&&vis[bh][1]==0){
            zxs=1;
        }else{
            zxs=2;
        }
    }
    s[zxs].push_back(bh);
  //  if(bh==7){
    //    cout<<"zxs"<<zxs<<endl;
 //   }
    vis[bh][d]=1;
    a[bh].s1=0x3f3f3f3f;
    s[d].pop_back();
    return ;
}
long long he;
int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        v.clear();
        s[1].clear();
        s[2].clear();
        s[3].clear();
        cin>>n;
        memset(a,0,sizeof(a));
        he=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){

            cin>>a[i].j1>>a[i].j2>>a[i].j3;

            a[i].xb=i;

            a[i].p=mxx1(a[i].j1,a[i].j2,a[i].j3);

            int hn=mxx2(a[i].j1,a[i].j2,a[i].j3);
            a[i].h=hn;

            if(a[i].p==1){
                a[i].s2=max(hn-a[i].j2,hn-a[i].j3);
                a[i].s1=min(hn-a[i].j2,hn-a[i].j3);
            }
            if(a[i].p==2){
                a[i].s2=max(hn-a[i].j1,hn-a[i].j3);
                a[i].s1=min(hn-a[i].j1,hn-a[i].j3);
            }
            if(a[i].p==3){
                a[i].s2=max(hn-a[i].j1,hn-a[i].j2);
                a[i].s1=min(hn-a[i].j1,hn-a[i].j2);
            }
//            cout<<a[i].s1<<" "<<a[i].s2<<endl;
            v.push_back(a[i].xb);

        }
        sort(v.begin(),v.end(),cmp1);
        for(int i=0;i<v.size();i++){
            if(a[v[i]].p==1){
                s[1].push_back(v[i]);
            }
            if(a[v[i]].p==2){
                s[2].push_back(v[i]);
            }
            if(a[v[i]].p==3){
                s[3].push_back(v[i]);
            }
        }
        while(s[1].size()>n/2||s[2].size()>n/2||s[3].size()>n/2){
            sort(s[1].begin(),s[1].end(),cmp2);
            if(s[1].size()>n/2){
  //              cout<<s[1].back()<<" "<<a[s[1].back()].s2<<endl;
                cr(1);
            }
            sort(s[2].begin(),s[2].end(),cmp2);
            if(s[2].size()>n/2){
     //           cout<<s[2].back()<<" "<<a[s[2].back()].s2<<endl;
                cr(2);
            }
            sort(s[3].begin(),s[3].end(),cmp2);
            if(s[3].size()>n/2){
 //               cout<<s[3].back()<<" "<<a[s[3].back()].s2<<endl;
                cr(3);
            }
        }
        for(int i=1;i<=3;i++){
            for(int j=0;j<s[i].size();j++){
                if(i==1){
                    he+=a[s[i][j]].j1;
      //              cout<<a[s[i][j]].j1<<" "<<s[i][j]<<" ";
                }
                if(i==2){
                    he+=a[s[i][j]].j2;
   //                 cout<<a[s[i][j]].j2<<" "<<s[i][j]<<" ";

                }
                if(i==3){
                    he+=a[s[i][j]].j3;
 //                   cout<<a[s[i][j]].j3<<" "<<s[i][j]<<" ";
                }
            }
//            cout<<endl;
        }
        cout<<he<<endl;
    }
    return 0;
}
