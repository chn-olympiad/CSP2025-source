#include <bits/stdc++.h>
using namespace std;
struct p
{
    int a;int b; int c;
};
bool cmp(int a,int b){
    return a > b;
}
int main(){
   
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    // int dp[1005][1005] = {};
    // int w[10005]= {};
    // int v[10005] = {};
    // int n,wei;
    // cin>>n>>wei;
    // for (int i = 1;i <= n;i++){
    //     cin>>w[i]>>v[i];
    // }
    
    // for (int i = 1;i <= n;i++){//v
    //     for (int j = 1;j <= w[i];j++){
    //        // dp[i][j] = v[i];
    //         dp[i][j] = v[i];
    //         if (j < wei){
    //             dp[i][j] = max(dp[i][j],dp[i][j+w[i]]-v[i]);
    //         }
    //     }
    // }
    // for (int i = 1;i <= n;i++){//v
    //     for (int j = 1;j <= wei;j++){
    //          cout<<dp[i][j]<<" ";
    //     }
    //      cout<<"\n";
    //  }
    // //cout<<dp[n][wei];
    int t;
    cin>>t;
    for (int tt = 0;tt < t;tt++){ 
        int n;
        cin>>n;
        int vec[105][3];
        int num[4] = {0,1,2,3};
        for (int i = 1;i <= n;i++){
            cin>>vec[i][1]>>vec[i][2]>>vec[i][3];
        }
        if (n == 2){
            int m1 = -1,id1 = 0;
            int m2 = -1,id2 = 0;
            for (int i = 1;i <= 3;i++){
                if (m1 < vec[1][i]){
                    m1 = vec[1][i];
                    id1 = i;
                }
            }
            for (int i = 1;i <= 3;i++){
                if (m2 < vec[2][i]){
                    m2 = vec[2][i];
                    id2 = i;
                }
            }
            if (id1 != id2){
                cout<<m1 + m2<<endl;
            }else{
                if (m1 > m2){
                    if (id1 == 1){
                        cout<<max(m1 + max(vec[2][2],vec[2][3]),max(m2 + vec[1][2],m2 + vec[1][3]))<<endl;
                    }else if (id1 == 2){
                        cout<<max(m1 + max(vec[2][1],vec[2][3]),max(m2 + vec[1][1],m2 + vec[1][3]))<<endl;
                    }else{
                        cout<<max(m1 + max(vec[2][2],vec[2][1]),max(m2 + vec[1][2],m2 + vec[1][1]))<<endl;
                    }
                }else{
                    if (id1 == 1){
                        cout<<max(m2 + max(vec[1][2],vec[1][3]),max(m1 + vec[2][2],m1 + vec[2][3])) <<endl;
                    }else if (id1 == 2){
                        cout<<max(m2 + max(vec[1][1],vec[1][3]),max(m1 + vec[2][1],m1 + vec[2][3]))<<endl;
                    }else{
                        cout<<max(m2 + max(vec[1][2],vec[1][1]),max(m1 + vec[2][2],m1 + vec[2][1]))<<endl;
                    }
                }
            }
        }else if(n == 4){
            int m1 = -1,id1 = 0;
            int m2 = -1,id2 = 0;
            int m3 = -1,id3 = 0;
            int m4 = -1,id4 = 0;
            for (int i = 1;i <= 3;i++){
                if (m1 < vec[1][i]){
                    m1 = vec[1][i];
                    id1 = i;
                }
            }
            for (int i = 1;i <= 3;i++){
                if (m2 < vec[2][i]){
                    m2 = vec[2][i];
                    id2 = i;
                }
            }
            for (int i = 1;i <= 3;i++){
                if (m3 < vec[3][i]){
                    m3 = vec[3][i];
                    id3 = i;
                }
            }
            for (int i = 1;i <= 3;i++){
                if (m4< vec[4][i]){
                    m4 = vec[4][i];
                    id4 = i;
                }
            }
            
            
                int sum2 = 0;
                int ma = 0;
                for (int a = 1;a <= 3;a++){
                    for (int b = 1; b<= 3;b++){
                        for (int c = 1;c <= 3;c++){
                            for (int d = 1;d <= 3;d++){
                                if (a==b && c != d || c == d && a != b || a == c && b != d || b == d && a != c|| a == d && c != b || c == b && a != d){
                                    sum2 += vec[1][a] + vec[2][b] + vec[3][c] + vec[4][d];
                                    if (sum2 > ma){
                                        ma = sum2;
                                    }
                                    sum2 = 0;
                                }
                                    
                            }
                        }
                    }
                }
                cout<<ma<<endl;
                // int mm1,mm2;
                // vector <int> vec2;
                // vec2.push_back(m1);
                // vec2.push_back(m2);
                // vec2.push_back(m3);
                // vec2.push_back(m4);
                // sort(vec2.begin(),vec2.end(),cmp);
                
                // if (m1 == vec2[0]){
                //     if (m2 == vec2[1]){
                //         cout<<m1 + m2 + max(m3,m4)<<endl;
                //     }else if(m3 == vec2[1]){
                //         cout<<m1 + m3 + max(m2,m4)<<endl;
                //     }else if(m4 == vec2[1]){
                //         cout<<m1 + m4 + max(m3,m2)<<endl;
                //     }
                // }else if(m2 == vec2[0]){
                //     if (m1 == vec2[1]){
                //         cout<<m1 + m2 + max(m3,m4)<<endl;
                //     }else if(m3 == vec2[1]){
                //         cout<<m2 + m3 + max(m1,m4)<<endl;
                //     }else if(m4 == vec2[1]){
                //         cout<<m2 + m4 + max(m3,m1)<<endl;
                //     }
                // }else if(m3 == vec2[0]){
                //     if (m1 == vec2[1]){
                //         cout<<m3 + m1 + max(m2,m4)<<endl;
                //     }else if(m2 == vec2[1]){
                //         cout<<m3 + m2 + max(m1,m4)<<endl;
                //     }else if(m4 == vec2[1]){
                //         cout<<m3 + m4 + max(m1,m2)<<endl;
                //     }
                // }else if(m4 == vec2[0]){
                //     if (m1 == vec2[1]){
                //         cout<<m4 + m1 + max(m2,m3)<<endl;
                //     }else if(m3 == vec2[1]){
                //         cout<<m3 + m4 + max(m2,m1)<<endl;
                //     }else if(m2 == vec2[1]){
                //         cout<<m4 + m2 + max(m1,m3)<<endl;
                //     }
                // }
            
        }else{
            int sum = 0;
            for (int i = 1;i <= n;i++){
                sum += max(max(vec[i][1],vec[i][2]),vec[i][3]);
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}