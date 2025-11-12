#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
multiset<pair<int,int> >a1;
multiset<pair<int,int> >a2;
multiset<pair<int,int> >a3;
multiset<pair<int,int> >::iterator it;
int a[4];
pair<int,int> mp(int a,int b){return make_pair(a,b);}
int max3(int a,int b,int c){return max(a,max(b,c));}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
     while(t--){
        int n;
        scanf("%d",&n);
        a1.clear(),a2.clear(),a3.clear();
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",a+1,a+2,a+3);
            if(max3(a[1],a[2],a[3])==a[1])
                a1.insert(mp(min(a[1]-a[2],a[1]-a[3]),a[1]));
            else if(max3(a[1],a[2],a[3])==a[2])
                a2.insert(mp(min(a[2]-a[1],a[2]-a[3]),a[2]));
            else a3.insert(mp(min(a[3]-a[1],a[3]-a[2]),a[3]));
        }
        int ans=0;
        if((int)a1.size()>n/2){
            int cnt=(int)a1.size()-n/2;
            while(cnt--)it=a1.begin(),ans+=((*it).second-(*it).first),a1.erase(it);
        }else if((int)a2.size()>n/2){
            int cnt=(int)a2.size()-n/2;
            while(cnt--)it=a2.begin(),ans+=((*it).second-(*it).first),a2.erase(it);
        }else if((int)a3.size()>n/2){
            int cnt=(int)a3.size()-n/2;
            while(cnt--)it=a3.begin(),ans+=((*it).second-(*it).first),a3.erase(it);
        }
        for(it=a1.begin();it!=a1.end();it++)ans+=((*it).second);
        for(it=a2.begin();it!=a2.end();it++)ans+=((*it).second);
        for(it=a3.begin();it!=a3.end();it++)ans+=((*it).second);
        printf("%d\n",ans);
     }
	return 0;
}
