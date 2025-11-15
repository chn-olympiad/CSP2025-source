#include <bits/stdc++.h>
using namespace std ;
#define int long long
string A[100003] ;
string B[100003] ;
string qA[100003] ;
string qB[100003] ;
int hsh[100003] ;
int hsh2[100003] ;
const int MD=998244353 ;
map <pair<int,int>,int> mp[100003] ;
void solve(){
    int l1=0,l2=0 ;
    int N,Q,i,j ;
    cin >> N >> Q ;
    for (i = 0 ; i < N ; i ++) cin >> A[i] >> B[i],l1+=(int)A[i].size()+(int)B[i].size() ;
    for (i = 0 ; i < N ; i ++){
        int tt=0 ;
        int nw=1 ;
        for (j = 0 ; j < (int)A[i].size() ; j ++){
            tt+=nw*(A[i][j]-'a') ;
            tt%=MD ;
            nw*=27 ;
            nw%=MD ;
        }
        hsh[i]=tt ;
        tt=0 ;
        nw=1 ;
        for (j = 0 ; j < (int)B[i].size() ; j ++){
            tt+=nw*(B[i][j]-'a') ;
            tt%=MD ;
            nw*=27 ;
            nw%=MD ;
        }
        hsh2[i]=tt ;
        mp[(int)A[i].size()][{hsh[i],hsh2[i]}]++ ;
    }
    for (i = 0 ; i < Q ; i ++) cin >> qA[i] >> qB[i],l2+=(int)qA[i].size()+(int)qB[i].size() ;
    // if (N<=1000&&Q<=1000&&l1<=2000&&l2<=2000){
        for (i = 0 ; i < Q ; i ++){
            string s1,s2 ;
            // cin >> s1 >> s2 ;
            s1=qA[i],s2=qB[i] ;
            if (s1.size()!=s2.size()){
                cout << 0 << endl ;
                continue ;
            }
            int X=(int)s1.size() ;
            int l=X-1,r=0 ;
            for (j = 0 ; j < X ; j ++){
                if (s1[j]!=s2[j]){l=j;break;}
            }
            for (j = X-1 ; j >=0 ; j --){
                if (s1[j]!=s2[j]){r=j;break;}
            }
            int ttt=0 ;
            if (l==X-1&&r==0){
                for (j = 0 ; j < X ; j ++){
                    int tt=0 ;
                    int tt2=0 ;
                    int nw=1 ;
                    for (int k = j ; k <= X ; k ++){
                        tt+=nw*(s1[k]-'a') ;
                        tt%=MD ;
                        tt2+=nw*(s2[k]-'a') ;
                        tt2%=MD ;
                        nw*=27 ;
                        nw%=MD ;
                        ttt+=mp[k-j+1][{tt,tt2}] ;
                    }
                }
            }
            else {
                for (j = 0 ; j <= l ; j ++){
                    int tt=0 ;
                    int tt2=0 ;
                    int nw=1 ;
                    for (int k = j ; k < r ; k ++){
                        tt+=nw*(s1[k]-'a') ;
                        tt%=MD ;
                        tt2+=nw*(s2[k]-'a') ;
                        tt2%=MD ;
                        nw*=27 ;
                        nw%=MD ;
                    }
                    for (int k = r ; k <= X ; k ++){
                        tt+=nw*(s1[k]-'a') ;
                        tt%=MD ;
                        tt2+=nw*(s2[k]-'a') ;
                        tt2%=MD ;
                        nw*=27 ;
                        nw%=MD ;
                        ttt+=mp[k-j+1][{tt,tt2}] ;
                    }
                }
            }
            cout << ttt << endl ;
        }
    // }
    // else {
    //     map <int,vector <pair<int,int>>> mpp ;
    //     map <int,map<int,vector <pair<int,int>>>> qpp ;
    //     for (i = 0 ; i < N ; i ++){
    //         int posa,posb ;
    //         for (j = 0 ; j < (int)A[i].size() ; i ++) if (A[i][j]=='b') posa=j ;
    //         for (j = 0 ; j < (int)B[i].size() ; i ++) if (B[i][j]=='b') posb=j ;
    //         mpp[posa-posb].push_back({min(posa,posb),(int)A[i].size()-max(posa,posb)-1}) ;
    //     }
    //     for (i = 0 ; i < Q ; i ++){
    //         if (qA[i].size()!=qB[i].size()) continue ;
    //         int posa,posb ;
    //         for (j = 0 ; j < (int)qA[i].size() ; i ++) if (qA[i][j]=='b') posa=j ;
    //         for (j = 0 ; j < (int)qB[i].size() ; i ++) if (qA[i][j]=='b') posb=j ;
    //         qpp[posa-posb][min(posa,posb)].push_back({i,(int)qA[i].size()-max(posa,posb)-1}) ;
    //     }
    //     std::map<int,map<int,vector <pair<int,int>>>>::iterator it=qpp.begin() ;
    //     while (it!=qpp.end()){
    //         int xx=(*it).first ;
    //         map <int,vector<pair<int,int>>> mp=(*it).second ;
    //         sort(mpp[xx].begin(),mpp[xx].end()) ;
    //         int cnt=0 ;
    //         std::map<int,map<int,vector <pair<int,int>>>>::iterator it2=mp.begin() ;
    //         vector<
    //         while (it2!=mp.end()){
    //             int yy=(*it2).first ;
    //             while (cnt<(int)mpp[xx].size()&&mpp[xx][cnt]<yy) cnt++ ;
    //             it2++ ;
    //         }
    //         it++ ;
    //     }
    //     for (i = 0 ; i < Q ; i ++){
            
    //     }
    // }
}
signed main(){
    freopen("replace.in","r",stdin) ;
    freopen("replace.out","w",stdout) ;
    int T ;
    // cin >> T ;
    T=1 ;
    while (T--) solve() ;
    return 0 ;
}