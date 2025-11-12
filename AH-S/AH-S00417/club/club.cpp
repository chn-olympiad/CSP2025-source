#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int t,n,a[N][4];
ll mymax(ll a,ll b){return a>b?a:b;}
bool cmp(int a,int b){return a>b;}
int count1(int n){
    int cnt=0;
    while(n){
        if(n&1)++cnt;
        n=n>>1;
    }
}
namespace task1{
    void solve(){
        int ans=0;
        for(int i=1;i<=3;++i){
            for(int j=1;j<=3;++j){
                if(i==j)continue;
                ans=max(ans,a[1][i]+a[2][j]);
            }
        }
        cout<<ans<<endl;
    }
}
namespace task2{
	void solve(){
        int ans=0,cnt[4]={0};
        for(int i=1;i<=3;++i){
            if(++cnt[i]>2){
                --cnt[i];
                continue;
            }
            for(int j=1;j<=3;++j){
                if(++cnt[j]>2){
                --cnt[j];
                continue;
                }
                for(int k=1;k<=3;++k){
                    if(++cnt[k]>2){
                    --cnt[k];
                    continue;
                }
				    for (int l=1;l<=3;++l){
                        if(++cnt[l]>2){
                        --cnt[l];
                        continue;
                        }
                        ans=max(ans,a[1][i]+a[2][j]+a[3][k]+a[4][l]);
                        --cnt[l];
                    }
                    --cnt[k];
				}
                --cnt[j];
            }
            --cnt[i];
        }

        cout<<ans<<endl;
    }
}
namespace task4{
    void solve(){
        int ans=0,cnt[4]={0};
        for(int i=1;i<=3;++i){
            if(++cnt[i]>5){
                --cnt[i];
                continue;
            }
            for(int j=1;j<=3;++j){
                if(++cnt[j]>5){
                --cnt[j];
                continue;
                }
                for(int k=1;k<=3;++k){
                    if(++cnt[k]>5){
                    --cnt[k];
                    continue;
                }
                    for (int l=1;l<=3;++l){
                        if(++cnt[l]>5){
                        --cnt[l];
                        continue;
                        }
                        for(int m=1;m<=3;++m){
                            if(++cnt[j]>5){
                                --cnt[m];
                                continue;
                            }
                            for(int n=1;n<=3;++n){
                                if(++cnt[n]>5){
                                --cnt[n];
                                continue;
                                }
                                for (int o=1;o<=3;++o){
                                    if(++cnt[o]>5){
                                    --cnt[o];
                                    continue;
                                }
                                    for(int p=1;p<=3;++p){
                                    if(++cnt[p]>5){
                                        --cnt[p];
                                        continue;
                                        }
                                        for(int q=1;q<=3;++q){
                                            if(++cnt[q]>5){
                                            --cnt[q];
                                            continue;
                                        }
                                            for (int r=1;r<=3;++r){
                                                if(++cnt[r]>5){
                                                --cnt[r];
                                                continue;
                                                }
                                                ans=max(ans,a[1][i]+a[2][j]+a[3][k]+a[4][l]+a[5][m]+a[6][n]+a[7][o]+a[8][p]+a[9][q]+a[10][r]);
                                                --cnt[r];
                                            }
                                            --cnt[q];
                                        }
                                        --cnt[p];
                                    }
                        
                                    --cnt[o];
                                }
                                --cnt[n];
                            }
                            --cnt[m];
                        }
                        --cnt[l];
                    }
                    --cnt[k];
                }
                --cnt[j];
            }
            --cnt[i];
        }

        cout<<ans<<endl;
    }
}
namespace task12{
    ll ans=0;
    int temp[N];
    void solve(){  
        for(int i=1;i<=n;++i)
            temp[i]=a[1][i];
        sort(temp+1,temp+1+n,cmp);
        for(int i=1;i<=n/2;++i)ans+=temp[i];
        cout<<ans<<endl;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        bool flag2=true;
        bool flag3=true;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=3;++j){
                cin>>a[i][j];
                if(j==2&&a[i][j]!=0)flag2=false;
                if(j==3&&a[i][j]!=0)flag3=false;
            }
        }
        if(n==2)task1::solve();
        else if(n==4)task2::solve();
        else if(n==10)task4::solve();

        else if(flag3==true){
            if(flag2==true)task12::solve();
            else{
				ll ans=0;
                for(int i=1;i<=n;++i)ans+=mymax(a[i][1],a[i][2]);
                cout<<ans<<endl;
            }
        }
        else{
			ll ans=0;
            for(int i=1;i<=n;++i)ans+=mymax(a[i][1],mymax(a[i][2],a[i][3]));
            cout<<ans<<endl;
		}
    }

    return 0;


}
