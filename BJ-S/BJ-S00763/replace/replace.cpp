#include<bits/stdc++.h>
using namespace std;
string s1[5000005],s2[5000005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,pos1,pos2,u,flag,cnt,shift = 0;
    int begin_n[200005],end_n[200005];
    string p1,p2,temp1,temp2;
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        cin>>temp1>>temp2;
        for(int j = 0;j<temp1.size();j++){
            if(temp1[j] != temp2[j]){
                if(temp1[j] != 'b' && temp2[j] != 'b') shift = 1;
                begin_n[i] = j;
                break;
            }
            else{
                if(temp1[j] != 'a') shift = 1;
            }
        }
        for(int j = temp1.size()-1;j>=0;j--){
            if(temp1[j] != temp2[j]){
                if(temp1[j] != 'b' && temp2[j] != 'b') shift = 1;
                end_n[i] = j;
                break;
            }
            else{
                if(temp1[j] != 'a') shift = 1;
            }
        }
        s1[i] = temp1;
        s2[i] = temp2;
    }
    for(int i = 1;i<=q;i++){
        cnt = 0;
        cin>>p1>>p2;
        if(p1.size() != p2.size()){
            cout<<0<<endl;
            continue;
        }
        for(int j = 0;j<p1.size();j++){
            if(p1[j] != p2[j]){
                pos1 = j;
                break;
            }
        }
        for(int j = p1.size()-1;j>=0;j--){
            if(p1[j] != p2[j]){
                pos2 = j;
                break;
            }
        }
        for(int j = 1;j<=n;j++){
            temp1 = s1[j];
            temp2 = s2[j];
            if(pos1<begin_n[j]){
                    continue;
            }
            if(pos1+temp1.size()-begin_n[j] > p1.size()){
                    continue;
            }
            if(end_n[j]-begin_n[j] != pos2-pos1){
                    continue;
            }
            if(temp1[begin_n[j]] != p1[pos1] || temp2[begin_n[j]] != p2[pos1] || temp1[end_n[j]] != p1[pos2] || temp2[end_n[j]] != p2[pos2]){
                    continue;
            }
            if(shift == 0){
                cnt++;
                continue;
            }
            flag = 0;
            for(int l = 0;l<temp1.size();l++){
                if(temp1[l] != p1[l+pos1-begin_n[j]] || temp2[l] != p2[l+pos1-begin_n[j]]){
                    cout<<l<<" "<<l+pos1-begin_n[j]<<endl;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                    continue;
            }
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
