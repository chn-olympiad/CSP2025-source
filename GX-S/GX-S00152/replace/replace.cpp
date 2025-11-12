#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200020][2];
struct sentence
{
    int l, r;
    string a="";
    string b="";

}qujian[20];
sentence qujian_o[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    for(int i=1;i<=n;i++){
        int len=s[i][1].length();
        for(int j=0;j<len;j++){
            if(s[i][1][j]!=s[i][2][j]){
                qujian_o[i].l=j;
                while(s[i][1][j]!=s[i][2][j]){
                    qujian_o[i].a+=s[i][1][j];
                    qujian_o[i].b+=s[i][2][j];
                    j++;
                }
                qujian_o[i].r=j-1;
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>s[n+i][1]>>s[n+i][2];
        int len1=s[n+i][1].length();
        int ans=0;
        int different_len=0,different_num=0;
        qujian[1].a="",qujian[1].b="";
        for(int j=0;j<len1;j++){
            if(s[n+i][1][j]!=s[n+i][2][j]){
                qujian[different_num].l=j;
                int k=j;
                different_num++;
                while(s[n+i][1][k]!=s[n+i][2][k]){
                    qujian[different_num].a+=s[n+i][1][k];
                    qujian[different_num].b+=s[n+i][2][k];
                    k++;
                }
                j=k;
                qujian[different_num].r=k-1;
            }
        }
        if(different_num>1){
            cout<<0<<endl;
            continue;
        }
        if(different_num==0){
            cout<<0<<endl;
            continue;
        }
        for(int j=1;j<=different_num;j++){
            for(int j1=1;j1<=n;j1++){
                if(qujian[different_num].a.length()!=qujian_o[j1].a.length()){
                    continue;
                }
                if(qujian_o[j1].a==qujian[different_num].a && qujian_o[j1].b==qujian[different_num].b){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
