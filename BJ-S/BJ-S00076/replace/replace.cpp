#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,Q=2e5+5;
int n,q;
string s[N][3];
string t[N][3];
map<pair<string,string>,bool> mp;
void subtask1(){
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
        mp[make_pair(s[i][1],s[i][2])]=true;
    }
    for(int pos=1;pos<=q;pos++){
        int ans=0;
        cin>>t[pos][1]>>t[pos][2];
        if(t[pos][1].length()!=t[pos][2].length()){
            cout<<0<<endl;
            continue;
        }
        int len=t[pos][1].length();
        int fi=0,ei=len-1;
        while(t[pos][1][fi]==t[pos][2][fi]) fi++;
        while(t[pos][1][ei]==t[pos][2][ei]) ei--;
        for(int i=0;i<len;i++){
            string str1="",str2="";
            for(int j=i;j<len;j++){

                str1=str1+t[pos][1][j];
                str2=str2+t[pos][2][j];
                if(i<=fi&&j>=ei&&mp[make_pair(str1,str2)]==true){
                    ans++;
                }

            }
        }
        cout<<ans<<endl;
    }

}
void subtask2(){
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];

    }
    for(int pos=1;pos<=q;pos++){
        int ans=0;
        cin>>t[pos][1]>>t[pos][2];
        int len=t[pos][1].length();
        int fi1=0,fi2=0,ei1=len-1,ei2;
        while(t[pos][1][fi1]=='a') fi1++;
        fi1--;
        ei1=len-(fi1+2);
        while(t[pos][1][fi2]=='a') fi2++;
        fi2--;
        ei2=len-(fi2+2);
        int minx=min(fi1,min(fi2,min(ei1,ei2)));
        for(int i=1;i<=n;i++){
            int len=s[i][1].length();
            int fi3=0,fi4=0,ei3=len-1,ei4;

            while(s[i][1][fi3]=='a') fi3++;
            fi3--;
            ei3=len-(fi3+2);
            while(s[i][1][fi4]=='a') fi4++;
            fi4--;
            ei4=len-(fi4+2);
            if(ei1-fi1==ei3-fi3&&ei2-fi2==ei4-fi4&&ei1-minx<=ei3&&ei1>=ei3&&fi1-minx<=fi3&&fi1>=fi3&&ei2-minx<=ei4&&ei2>=ei4&&fi2-minx<=fi4&&fi2>=ei4){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    if(n<=1e2){
        subtask1();
    }
    else if(q==1) subtask2();
    fclose(stdin);
    fclose(stdout);
    return 0;
}



