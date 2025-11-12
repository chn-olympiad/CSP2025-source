#include<bits/stdc++.h>
using namespace std;
struct Node{
    int gap;int to;
    bool operator<(const Node &tha)const{
        return gap>tha.gap;
    }
};
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}
vector<priority_queue<Node> >q(3);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long ans=0;
        int c[3]{0,0,0};
        for(int i=1;i<=n;++i){
            vector<pair<int,int> >a;
            for(int j=0;j<3;++j){
                int x;
                cin>>x;
                a.push_back(make_pair(x,j));
            }
            sort(a.begin(),a.end(),cmp);
            if(c[a[0].second]<n/2){
                ans+=a[0].first;
                c[a[0].second]++;
                Node st;
                st.gap=a[0].first-a[1].first;
                st.to=a[1].second;
                q[a[0].second].push(st);
                st.gap=a[0].first-a[2].first;
                st.to=a[2].second;
                q[a[0].second].push(st);
            }
            else{
                Node st=q[a[0].second].top();
                if(st.gap<a[0].first-a[1].first){
                    c[st.to]++;
                    ans-=st.gap;
                    ans+=a[0].first;
                    q[a[0].second].pop();
                    Node stt;
                    stt.gap=a[0].first-a[1].first;
                    stt.to=a[1].second;
                    q[a[0].second].push(stt);
                    stt.gap=a[0].first-a[2].first;
                    stt.to=a[2].second;
                    q[a[0].second].push(stt);
                }
                else{
                    ans+=a[1].first;
                    c[a[1].second]++;
                    Node stt;
                    stt.gap=a[1].first-a[2].first;
                    stt.to=a[2].second;
                    q[a[1].second].push(stt);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
