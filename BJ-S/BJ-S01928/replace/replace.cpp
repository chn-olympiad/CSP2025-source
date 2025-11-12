#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    string s_y[200005]={ },s_h[200005]={ };
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>s_y[i]>>s_h[i];
    while(q--){
        string part,s2s,th;
        int ans=0,flag=0,k=0;
        string question,expect_ans;
        cin>>question>>expect_ans;
        for(int i=0;i<n;i++)if(question[i]!=expect_ans[i])part+=question[i];
        int l=part.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<l;j++){
                s2s+=part[j];
                if(s2s==s_y[i]){
                    ans++;
                    flag=1;
                }
                if(j==n && flag==0){
                    k++;
                    j=1+k;
                    s2s={ };
                }
            }
            flag=0;
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
