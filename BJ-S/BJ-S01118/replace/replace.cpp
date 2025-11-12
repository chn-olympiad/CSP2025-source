#include<bits/stdc++.h>
using namespace std;
int a,b;
string l[1005],r[1005];
string L[1005],R[1005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d %d",&a,&b);
    for(int i=1;i<=a;i++){
        cin>>l[i]>>r[i];
    }
    for(int i=1;i<=b;i++){
        cin>>L[i]>>R[i];
        if(L[i].size()!=R[i].size()){
            printf("0\n");
            continue;
        }
        int ans=0;
        for(int j=1;j<=a;j++){
            for(int k=0;k+l[j].size()<=L[i].size();k++){
                if(L[i].substr(k,l[j].size())==l[j]){
                    //cout<<L[i]<<" "<<R[i]<<" "<<L[i].substr(0,k)+r[j]+L[i].substr(k+l[j].size(),L[i].size()-k-l[j].size())<<"\n";
                    if(L[i].substr(0,k)+r[j]+L[i].substr(k+l[j].size(),L[i].size()-k-l[j].size())==R[i]){
                        ans++;
                    }else{
                        break;
                    }
                }else{
                    continue;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
