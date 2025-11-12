#include<bits/stdc++.h>
using namespace std;

int n,q,cnt;
string s1[200005],s2[200005];
bool t;
int l[200005],r[200005],kmp[200005];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> s1[i] >> s2[i];
        if(!t)continue;
        int l2=0;
        for(int j=0; j<s1[i].size(); j++){
            if(s1[i][j]!='a'&&s1[i][j]!='b'){
                t=false;
            }
            else if(s2[i][j]!='a'&&s2[i][j]!='b'){
                t=false;
            }
            else{
                if(s1[i][j]=='b'){
                    if(l[i]!=0) t=false;
                    l[i]=j;
                    r[i]=s1[i].size()-j-1;
                }
                if(s2[i][j]=='b'){
                    if(l2!=0)t=false;
                    l2=j;
                }
            }
        }
        if(t){
            kmp[i]=l2-l[i];
        }
    }
    if(t){
        while(q--){
            t=true;cnt=0;
            string t1,t2;
            cin >> t1 >> t2;
            int l1=0,l2=0,r1=0,kmp1=0;
            for(int j=0; j<t1.size(); j++){
                if(t1[j]!='a'&&t1[j]!='b'){
                    t=false;
                }
                else if(t2[j]!='a'&&t2[j]!='b'){
                    t=false;
                }
                else{
                    if(t1[j]=='b'){
                        if(l1!=0) t=false;
                        l1=j;
                        r1=t1.size()-j-1;
                    }
                    if(t2[j]=='b'){
                        if(l2!=0)t=false;
                        l2=j;
                    }
                }
            }
            if(!t){
                printf("0\n");
                continue;
            }
            kmp1=l2-l1;
            for(int i=1; i<=n; i++){
                if(kmp[i]==kmp1){
                    if(l[i]<=l1&&r[i]<=r1)cnt++;
                }
            }
            printf("%d\n",cnt);
        }
        return 0;
    }
    while(q--){
            cnt=0;
        string t1,t2;
        cin >> t1 >> t2;
        for(int i=1; i<=n; i++){
            string s=t1;
            for(int j=0; j+s1[i].size()-1<s.size(); j++){
                bool t=true;
                for(int k=0; k<s1[i].size(); k++){
                    if(s[j+k]!=s1[i][k]){
                        t=false;
                        break;
                    }
                }
                if(t){
                    for(int k=0; k<s1[i].size(); k++){
                        s[j+k]=s2[i][k];
                    }
                    if(s==t2)cnt++;
                    s=t1;
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
