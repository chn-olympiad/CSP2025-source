#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string func[n+1][3];
    string ques[q+1][3];
    for(int i=1;i<=n;i++){
        cin>>func[i][1]>>func[i][2];
    }
    for(int i=1;i<=q;i++){
        cin>>ques[i][1]>>ques[i][2];
        int ans=0;
        int x=1;
        for(int j=1;j<=n;j++){
            for(int k=0;k<ques[i][1].size();k++){
                if(func[j][1][0]==ques[i][1][k]){
                    x=1;
                    for(int l=0;l<=func[j][1].size();l++){
                        if(func[j][1][l]!=ques[i][1][k+l]||func[j][2][l]!=ques[i][2][k+l]){
                            x=0;
                            break;
                        }
                    }
                }
                if(x){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}