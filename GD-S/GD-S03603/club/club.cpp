#include<bits/stdc++.h>
using namespace std;

int t,n;
long long ans; 
vector< vector<int> > a(100005,vector<int>(3));
vector<int> A(100005);
vector< vector<int> > B(100005,vector<int>(3));
int left_max_a [100005];
bool is_A = true,is_B=true;

bool cmp(int a,int b){
    return a>b;
}

bool cmp2(vector<int> a,vector<int> b){
    return a[2] > b[2];
}

void dfs(int i,long long a_sum,vector<int> pn){
    if(i > n){
        // cout<<a_sum<<endl;
        ans = max(ans,a_sum);
        return;
    }

    if(left_max_a[i] + a_sum < ans) return;
    
    vector<int> tmp;
    bool flag[3];
    tmp = a[i];
    sort(tmp.begin(),tmp.end(),cmp);

    vector<int> idx;
    for(int k=0;k<3;k++){
        for(int j=0;j<3;j++){
            if(tmp[k] == a[i][j] && !flag[j]){
                flag[j] = true;
                idx.push_back(j);
                break;
            }
        }
    }
    // printf("%d %d %d\n",idx[0],idx[1],idx[2]);

    for(int k=0;k<3;k++){
        int j = idx[k];
        pn[j] ++;
        if(pn[j] <= n/2){
            dfs(i+1,a_sum+a[i][j],pn);
        }
        pn[j] --;
    }
}

int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;
    // t = 1;
    for(int ti=0;ti<t;ti++){
        ans = 0;
        cin>>n;

        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
                left_max_a[i] = max(left_max_a[i],a[i][j]);
            }

            if(!is_B) continue;
            vector<int> tmp(3);
            tmp[0] = a[i][0];
            tmp[1] = a[i][1];
            tmp[2] = abs(tmp[0] - tmp[1]);
            B[i] = tmp;
            if(a[i][2] != 0) is_B = false;

            if(!is_A) continue;
            A[i] = a[i][0];
            if(a[i][1] != 0 || a[i][2] != 0) is_A = false;
        }

        for(int i=n-1;i>=1;i--){
            left_max_a[i] = left_max_a[i+1] + left_max_a[i];
        }

        if(is_A){
            sort(A.begin(),A.end(),cmp);
            for(int i=0;i<n/2;i++){
                ans += A[i];
            }
        }
        else if(is_B && n>= 200){
            sort(B.begin(),B.end(),cmp2);
            int c1=0,c2=0;
            for(int i=0;i<n;i++){
                // printf("%d %d %d\n",B[i][0],B[i][1],B[i][2]);
                if(B[i][0] > B[i][1] && c1 < n/2){
                    c1 ++;
                    // cout<<"1 "<<c1<<" "<<ans<<endl;
                    ans += B[i][0];
                }
                else if(B[i][0] < B[i][1] && c2 < n/2){
                    c2 ++;
                    // cout<<"2 "<<c2<<" "<<ans<<endl;
                    ans += B[i][1];
                }
                else if(c1 < n/2){
                    c1 ++;
                    // cout<<"1 "<<c1<<" "<<ans<<endl;
                    ans += B[i][0];
                }
                else{
                    c2 ++;
                    // cout<<"2 "<<c2<<" "<<ans<<endl;
                    ans += B[i][1];
                }
                
            }
        }
        else{
            vector<int> pn(3,0);
            dfs(0,0,pn);
        }
        
        
        cout<<ans<<endl;
    }

    return 0;
}