#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
const int N=1e5+5;
struct Node
{
    int Ac,Bc,Cc;
};
Node Stu[N];
vector<int>Ant,Bnt,Cnt;
ll Calc_sum()
{
    ll Summ=0;
    int Asz=Ant.size(),Bsz=Bnt.size(),Csz=Cnt.size();
    for (int i=0;i<Asz;i++) Summ+=Stu[Ant[i]].Ac;
    for (int i=0;i<Bsz;i++) Summ+=Stu[Bnt[i]].Bc;
    for (int i=0;i<Csz;i++) Summ+=Stu[Cnt[i]].Cc;
    return Summ;
}
struct Change
{
    int Id,Cost;
};
bool Cmp(Change A,Change B)
{
    return A.Cost<B.Cost;
}
void Solve()
{
    int n;
    cin>>n;
    Ant.clear(),Bnt.clear(),Cnt.clear();
    int Lim=(n>>1);
    for (int i=1;i<=n;i++)
    {
        cin>>Stu[i].Ac>>Stu[i].Bc>>Stu[i].Cc;
        if (Stu[i].Ac>=Stu[i].Bc&&Stu[i].Ac>=Stu[i].Cc) Ant.push_back(i);
        else if (Stu[i].Bc>=Stu[i].Ac&&Stu[i].Bc>=Stu[i].Cc) Bnt.push_back(i);
        else Cnt.push_back(i);
    }
    ll Summ=Calc_sum();
    if (Lim>=Ant.size()&&Lim>=Bnt.size()&&Lim>=Cnt.size())
    {
        cout<<Summ<<'\n';
        return;
    }
    if (Ant.size()>Lim)
    {
        int Asz=Ant.size();
        int Must_chg=Asz-Lim;
        vector<Change>Costs;
        for (int i=0;i<Asz;i++)
            if (Stu[Ant[i]].Bc>=Stu[Ant[i]].Cc) Costs.push_back({Ant[i],Stu[Ant[i]].Ac-Stu[Ant[i]].Bc});
            else Costs.push_back({Ant[i],Stu[Ant[i]].Ac-Stu[Ant[i]].Cc});
        sort(Costs.begin(),Costs.end(),Cmp);
        for (int i=0;i<Must_chg;i++)
            Summ-=Costs[i].Cost;
    }
    if (Bnt.size()>Lim)
    {
        int Bsz=Bnt.size();
        int Must_chg=Bsz-Lim;
        vector<Change>Costs;
        for (int i=0;i<Bsz;i++)
            if (Stu[Bnt[i]].Ac>=Stu[Bnt[i]].Cc) Costs.push_back({Bnt[i],Stu[Bnt[i]].Bc-Stu[Bnt[i]].Ac});
            else Costs.push_back({Bnt[i],Stu[Bnt[i]].Bc-Stu[Bnt[i]].Cc});
        sort(Costs.begin(),Costs.end(),Cmp);
        for (int i=0;i<Must_chg;i++)
            Summ-=Costs[i].Cost;
    }
    if (Cnt.size()>Lim)
    {
        int Csz=Cnt.size();
        int Must_chg=Csz-Lim;
        vector<Change>Costs;
        for (int i=0;i<Csz;i++)
            if (Stu[Cnt[i]].Ac>=Stu[Cnt[i]].Bc) Costs.push_back({Cnt[i],Stu[Cnt[i]].Cc-Stu[Cnt[i]].Ac});
            else Costs.push_back({Cnt[i],Stu[Cnt[i]].Cc-Stu[Cnt[i]].Bc});
        sort(Costs.begin(),Costs.end(),Cmp);
        for (int i=0;i<Must_chg;i++)
            Summ-=Costs[i].Cost;
    }
    cout<<Summ<<'\n';
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while (T--)
        Solve();
    return 0;
}
