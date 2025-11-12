#include<bits/stdc++.h>
using namespace std;

int a[10005];
int n,cnt=0;
set<vector<int> > s;

void dfs(int ind,int amax,vector<int> subseq,int chosen){
    if(ind==0){
        vector<int> next;
        next.push_back(ind);
        dfs(ind+1,a[ind],next,1);
        dfs(ind+1,0,subseq,0);
    }
    if(chosen>=3 || ind==n){
        int sum=0;
        for(vector<int>::iterator it=subseq.begin();it!=subseq.end();it++){
            sum+=a[*it];
        }
        if(sum>2*amax){
            s.insert(subseq);
        }
    }
    if(ind==n){
        return ;
    }
    if(ind<=n-1){
        dfs(ind+1,amax,subseq,chosen);
        subseq.push_back(ind);
        amax=max(amax,a[ind]);
        dfs(ind+1,amax,subseq,chosen+1);
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0<<endl;
        return 0;
    }
    if(n==3){
        int a1=a[0];
        int a2=a[1];
        int a3=a[2];
        if(a1+a2>a3 && a3+a2>a1 && a1+a3>a2){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
        return 0;
    }
    vector<int> e;
    dfs(0,0,e,0);
    cout<<s.size()<<endl;
    return 0;
}
