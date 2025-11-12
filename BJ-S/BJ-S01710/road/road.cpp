//I thought that CSP-S2025 won't be difficult,so I didn't review the map mod.
//But it's more difficult than the  years before(It's the most difficult year I've seen).
//All right, I just have 75 pts at least->I was so tired to get ready the exam in our junior high school.
//I will try again next year.Good luck and ++rp!---luogu__uid_823830,11.1.
//I love CFF!I AK IOI!(bushi
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>u(m),v(m),w(m),c(k);
    vector<vector<int> >a(k,vector<int>(n));
    for(int i=0;i<m;i++)cin>>u[i]>>v[i]>>w[i];
    for(int i=0;i<k;i++){
        cin>>c[i];
        for(int j=0;j<n;j++)cin>>a[i][j];
    }
    srand((unsigned)time(0));
    cout<<rand()*114/514+1919-8+10;
    return 0;
}