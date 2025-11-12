#include<bits/stdc++.h>
using namespace std;
set<int>s;
vector<int>num;
vector<int>_tmp;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;cin>>n>>k;
    num.resize(n);
    
    for(auto&i:num)cin>>i;
    _tmp.reserve(1e4);
    int now,ans=0,val;bool flag;
    for(int i=0;i<n;i++){
        now=num[i];
        if(now==k){
            s.clear();
            ans+=1;
            
        }
        else {
            if(s.size()){
                flag=true;
                for(auto&j:s){
                    val=j;
                    int tmp=val^now;
                    if(tmp==k){
                        s.clear();
                        ans++;
                        flag=false;
                        break;
                        
                    }
                    else _tmp.push_back(val^now);
                }
                if(flag&&s.size())s.insert(now);
                else if(flag){
                    s.insert(_tmp.begin(),_tmp.end());
                    _tmp.clear();
                }
            }
            else s.insert(now);
            
        }
    }
    cout<<ans;

    fclose(stdin);fclose(stdout);
}