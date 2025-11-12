#include<bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);


    int t;
    cin>>t;



    while(t>0){
        t--;
        int n;
        cin>>n;

        vector<pair<int,int>> a1;
        vector<pair<int,int>> a2;
        vector<pair<int,int>> a3;

        int ans[n+50];
        for(int i =0 ;i<n+10;i++){
            ans[i] = 0;
        }

        for(int i=0;i<n;i++){
            int a_1;
            int a_2;
            int a_3;

            cin>>a_1>>a_2>>a_3;
            a1.push_back({a_1,i});
            a2.push_back({a_2,i});
            a3.push_back({a_3,i});
        }

        sort(a1.begin(),a1.end());
        sort(a2.begin(),a2.end());
        sort(a3.begin(),a3.end());


        int cnt_1=0;
        int cnt_2=0;
        int cnt_3=0;
        int v=0;
        while((cnt_1+cnt_2+cnt_3)<n){
            while(ans[a1.back().second]!=0){
                a1.pop_back();
            }
            while(ans[a2.back().second]!=0){
                a2.pop_back();
            }
            while(ans[a3.back().second]!=0){
                a3.pop_back();
            }

            int val1 = a1.back().first;
            int val2 = a2.back().first;
            int val3 = a3.back().first;


            if(cnt_1<=n/2&&(val1>=val2 && val1>=val3)){
                ans[a1.back().second] = 1;
                cnt_1++;
                v+=val1;
            }else if(cnt_2<=n/2&&(val2>=val1&&val2>=val3)){
                ans[a2.back().second] = 2;
                cnt_2++;
                v+=val2;
            }else if(cnt_3<=n/2&&(val3>=val1&&val3>=val2)){
                ans[a3.back().second] = 3;
                cnt_3++;
                v+=val3;
            }
        }
        cout<<v<<'\n';
    }
    return 0;
}
