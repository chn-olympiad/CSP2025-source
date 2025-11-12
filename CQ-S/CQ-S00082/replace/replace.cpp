#include<bits/stdc++.h>
const int N=2e5+5,L=5e6+5;
int n,q,L1,L2,ls[N],lt[N];
std::string s1[N],s2[N],t1[N],t2[N];
namespace Task_1_5{
    bool chk(){ return n<=1000&&q<=1000&&L1<=2000&&L2<=2000; }
    const int N=1e3+5,L=2e3+5;
    const unsigned long long base=100;
    unsigned long long pwr[L];
    unsigned long long hs1[N],hs2[N],ht1[L],ht2[L];
    void work(){
        pwr[0]=1; for(int i=1;i<L;i++) pwr[i]=pwr[i-1]*base;
        for(int i=1;i<=n;i++) for(int j=1;j<=ls[i];j++)
            hs1[i]=hs1[i]*base+s1[i][j],hs2[i]=hs2[i]*base+s2[i][j];
        for(int t=1;t<=q;t++){
            for(int j=1;j<=lt[t];j++)
                ht1[j]=ht1[j-1]*base+t1[t][j],ht2[j]=ht2[j-1]*base+t2[t][j];
            int cnt=0;
            for(int i=1;i<=n;i++) for(int j=1;j+ls[i]-1<=lt[t];j++){
                if(ht1[j+ls[i]-1]-ht1[j-1]*pwr[ls[i]]==hs1[i]){
                    if(ht1[lt[t]]-hs1[i]*pwr[j-1]+hs2[i]*pwr[j-1]==ht2[lt[t]])
                        cnt++;
                }
            }
            std::cout<<cnt<<"\n";
        }
    }
}
namespace Task_B{
    bool chk(){
        for(int i=1;i<=n;i++){
            if(std::count(s1[i].begin(),s1[i].end(),'a')!=ls[i]-1||std::count(s1[i].begin(),s1[i].end(),'b')!=1) return false;
            if(std::count(s2[i].begin(),s2[i].end(),'a')!=ls[i]-1||std::count(s2[i].begin(),s2[i].end(),'b')!=1) return false;
        }
        for(int i=1;i<=q;i++){
            if(std::count(t1[i].begin(),t1[i].end(),'a')!=lt[i]-1||std::count(t1[i].begin(),t1[i].end(),'b')!=1) return false;
            if(std::count(t2[i].begin(),t2[i].end(),'a')!=lt[i]-1||std::count(t2[i].begin(),t2[i].end(),'b')!=1) return false;
        }
        return true;
    }
    std::vector<std::pair<int,int> > st[L*2];
//    struct Binary_Indexed_Tree{
//        std::vector<int> c;
//        int n;
//        void init(int _n){ n=_n,c.resize(n+5,0); }
//        int lowbit(int x){ return x&-x; }
//        void modify(int pos){ for(int i=pos;i<=n;i+=lowbit(i)) c[i]++; }
//        int query(int pos){
//            int res=0;
//            for(int i=pos;i>=1;i-=lowbit(i)) res+=c[i];
//            return res;
//        }
//    }bit;
//    int ans[N];
//    struct query{
//        int lm,rm,id;
//    };
//    std::vector<query> qry[L*2];
    void work(){
        for(int i=1;i<=n;i++){
            int p1=s1[i].find('b'),p2=s2[i].find('b');
            st[p1-p2+L].emplace_back(p1-1,ls[i]-p2);
        }
        
        for(int i=1;i<=q;i++){
            int p1=t1[i].find('b'),p2=t2[i].find('b'),ans=0;
//            qry[p1-p2+L].push_back({p1-1,lt[i]-p2,i});
            for(auto [llim,rlim]:st[p1-p2+L]){
                ans+=(p1-1>=llim&&lt[i]-p2>=rlim);
            }
            std::cout<<ans<<"\n";
        }
//        for(int i=0;i<L*2;i++) if(!st[i].empty()){
//            std::vector<int> val;
//            for(auto j:st[i]) val.push_back(j.second);
//            std::sort(val.begin(),val.end());
//            val.erase(std::unique(val.begin(),val.end()),val.end());
//            std::sort(st[i].begin(),st[i].end());
//            bit.init(val.size());
//            for(auto &[l,r]:st[i]){
//                r=std::lower_bound(val.begin(),val.end(),r)-val.begin()+1;
//            }
//            std::sort(qry[i].begin(),qry[i].end(),[](const query &a,const query &b){
//                return a.lm<b.lm;
//            });
//            for(int j=0,k=-1;j<(int)qry[i].size();j++){
//                for(;k+1<(int)st[i].size()&&st[i][k+1].first<=qry[i][j].lm;)
//                    k++,bit.modify(st[i][k].second);
//                int pos=std::upper_bound(val.begin(),val.end(),qry[i][j].rm)-val.begin();
//                ans[qry[i][j].id]=bit.query(pos);
//            }
//        }
//        for(int i=1;i<=q;i++) std::cout<<ans[i]<<"\n";
    }
}
namespace Other{
    void work(){
        for(int i=1;i<=q;i++) std::cout<<"0\n";
    }
}
int main(){
//    freopen("D:/csps/down/replace/replace4.in","r",stdin);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr),std::cout.tie(nullptr);
    std::cin>>n>>q;
    for(int i=1;i<=n;i++){
        std::cin>>s1[i]>>s2[i];
        L1+=s1[i].size(),ls[i]=s1[i].size();
        s1[i]=' '+s1[i],s2[i]=' '+s2[i];
    }
    for(int i=1;i<=q;i++){
        std::cin>>t1[i]>>t2[i];
        L2+=t1[i].size(),lt[i]=t1[i].size();
        t1[i]=' '+t1[i],t2[i]=' '+t2[i];
    }/*
    if(Task_1_5::chk()) Task_1_5::work();
    else */if(Task_B::chk()) Task_B::work();
    else Other::work();
    return 0;
}

