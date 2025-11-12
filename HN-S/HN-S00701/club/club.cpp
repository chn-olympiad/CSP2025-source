#include<bits/extc++.h>
#include<bits/stdc++.h>
#define endl '\n'
#define _rb_tree_ \
__gnu_pbds::tree<int,__gnu_pbds::null_type,greater<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>
using namespace std;
// 最多 3 部门 1e5 个人。
struct _{
    int a,b,c,maxx;
    int& operator[](size_t i){
        if(i==1) return a;
        if(i==2) return b;
        if(i==3) return c;
        if(i==4) return maxx;
        return a;
    }
};
template<typename A,typename B,typename C>
void dfs(int idx,A a,B& mask,C& st,long long& ans,int n){
    if(idx==n+1){
        //for(int i=1;i<idx;i++)cout<<mask[i];
        long long sum=0;
        for(int i=1;i<idx;i++){
            sum+=a[i][mask[i]];
        }
        //cout<<": "<<sum<<endl;
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=3;i++){
        if(st[i]==n/2)continue;
        mask[idx]=i,st[i]++;
        dfs(idx+1,a,mask,st,ans,n);
        st[i]--;
    }
}
int n,t;
bool f1,f2; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
        cin>>n;
        long long ans=0;
        vector<_> a(n+1);
        vector<int> st(4);
        for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3],a[i][4]=max({a[i][1],a[i][2],a[i][3]}),f1|=(a[i][2]),f2|=(a[i][3]);
        if(!f1&&!f2){
        	sort(a.begin()+1,a.end(),[](_& a,_& b){return a[4]>b[4];});
        	for(int i=1;i<=n/2;i++)ans+=a[i][1];
        	cout<<ans<<endl;
        	continue;
		}
        if(n<=10){
            vector<int> mask(n+1);
            dfs(1,a,mask,st,ans,n);
            cout<<ans<<endl;
            continue;
        }
        sort(a.begin()+1,a.end(),[](_& a,_& b){return a[4]>b[4];});
        //vector<_rb_tree_> rnk(4);
        //for(int i=1;i<=n;i++){
        //    rnk[1].insert(a[i][1]);
        //    rnk[2].insert(a[i][2]);
        //    rnk[3].insert(a[i][3]);
        //}
        //auto find_kth=[&](int x,int idx){
        //    return rnk[idx].order_of_key(x);
        //};
        auto Max=[&](int x,int y,int z){
            if(x==y&&x==z){
                return pair<int,int>{x,(st[1]<=st[2]&&st[1]<=st[3]?1:(st[2]<=st[1]&&st[2]<=st[3]?2:(st[3]<=st[1]&&st[3]<=st[2]?3:1)))};
            }else if(x==y){
                if(y>z){
                    return pair<int,int>{x,(st[1]<=st[2]?1:2)};
                }else{
                    return pair<int,int>{z,3};
                }
            }else if(x==z){
                if(z>y){
                    return pair<int,int>{x,(st[1]<=st[3]?1:3)};
                }else{
                    return pair<int,int>{y,2};
                }
            }else{
                int res=max({x,y,z});
                if(res==x) return pair<int,int>{res,1};
                if(res==y) return pair<int,int>{res,2};
                else return pair<int,int>{res,3};
            }
        };
        for(int i=1;i<=n;i++){
            auto p=Max(a[i][1],a[i][2],a[i][3]);
            if(st[p.second]==n/2){
                if(p.second==1){
                    if(st[2]==n/2) st[3]++,ans+=a[i][3];
                    else if(st[3]==n/2) st[2]++,ans+=a[i][2];
                    else{
                        if(a[i][2]>a[i][3]){
                            st[2]++,ans+=a[i][2];
                        }else if(a[i][2]==a[i][3]){
                            if(st[2]<=st[3])st[2]++,ans+=a[i][2];
                            else st[3]++,ans+=a[i][3];
                        }else{
                            st[3]++,ans+=a[i][3];
                        }
                    }
                }else if(p.second==2){
                    if(st[3]==n/2) st[1]++,ans+=a[i][1];
                    else if(st[1]==n/2) st[3]++,ans+=a[i][3];
                    else{
                        if(a[i][1]>a[i][3]){
                            st[1]++,ans+=a[i][1];
                        }else if(a[i][1]==a[i][3]){
                            if(st[1]<=st[3])st[1]++,ans+=a[i][1];
                            else st[3]++,ans+=a[i][3];
                        }else{
                            st[3]++,ans+=a[i][3];
                        }
                    }
                }else{
                    if(st[1]==n/2) st[2]++,ans+=a[i][2];
                    else if(st[2]==n/2) st[1]++,ans+=a[i][1];
                    else{
                        if(a[i][1]>a[i][2]){
                            st[1]++,ans+=a[i][1];
                        }else if(a[i][1]==a[i][2]){
                            if(st[1]<=st[2])st[1]++,ans+=a[i][1];
                            else st[2]++,ans+=a[i][2];
                        }else{
                            st[2]++,ans+=a[i][2];
                        }
                    }
                }
            }else{
                st[p.second]++,ans+=p.first;
            }
        }
        cout<<ans<<endl;
	}
	return 0;
}
