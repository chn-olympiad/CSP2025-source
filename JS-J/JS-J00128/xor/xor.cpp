#include<bits/stdc++.h>
#define int long long
using namespace std;
string two(int a){
    if(a==0)return "0";
    string s="";
    while(a>0){
        char c=(a%2)+'0';
        s+=c;
        a/=2;
    }
    return s;
}
int ten(string a){
    int d=1;
    if(a=="0")return 0;
    if(a=="1")return 1;
    for(int i=a.size()-2;i>=0;i--){
        d*=2;
        if(a[i]=='1')d++;
    }
    return d;
}
int Xor(int a,int b){
    string A=two(a);
    string B=two(b);
    string ans;
    if(A.size()<B.size())swap(A,B);
    for(int i=0;i<=B.size()-1;i++){
        char c;
        if(A[i]=='1'&&B[i]=='1')c='0';
        else c='1';
        ans+=c;
    }
    if(A.size()!=B.size())
        for(int i=B.size();i<=A.size()-1;i++){
            ans+=A[i];
        }
    return ten(ans);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
    int n;
    cin>>n;  
    int k;
    cin>>k;  
    vector<int> a;
    vector<bool> vist;
    set<int> c;
    for(int i=1;i<=n;i++){
        int b;
        cin>>b;
        a.push_back(b);
        vist[i]=(b==k);
        c.insert(b);
    }
    if(c.size()==1){
        cout<<n/2;
        return 0;
    }
    else if(c.size()==2){
        int ans1=0,ans2=0;
        for(auto i:a){
            if(i==1)ans1++;
            else ans2++;
        }
        cout<<max(ans1,ans2);
        return 0;
    }else{
        int ans=0;
        // cout<<1;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<=n-1;j++){
                if(vist[j])break;
                int sum=a[i];
                for(int z=i+1;z<=j;z++){
                    sum=Xor(sum,a[z]);
                }
                if(sum==k){
                    ans++;
                    i=j;
                    break;
                }
            }
        }
        cout<<ans;
    }
    return 0;
} 