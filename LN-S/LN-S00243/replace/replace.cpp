#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
string s1[200005],s2[200005];
string t1,t2,t3;
string x,y,z;
int main(){
    freopen("replace1.in","r",stdin);
    freopen("replace1.out","w",stdout);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> s1[i] >> s2[i];

//        cout << s1[i] << s2[i] <<endl;
    }
    for(int i=1;i<=q;i++){
        ans=0;
        cin >> t1 >> t2;
        int len1=t1.size(),len2=t2.size();
        for(int j=1;j<=n;j++){//s1s2
            for(int k=0;k<t1.size();k++){//t1t2
                if(t1[k]==t2[k]){
//                    cout <<t1[k] << "PASS" << s1[k] << endl;
                    continue;
                }
                //fen duan
//                cout << "GO" << endl;
                bool status=true;
                for(int l=0;l<s1[j].size();l++){
//                    cout << s1[j][l] << " COMP " << t1[k+l] << endl;
                    if(s1[j][l]!=t1[k+l]) status=false;
                }
                //
                if(status==true){
                    for(int l=1;l<s1[j].size();l++) t1[k+l]=s2[j][l];
                }
                if(t1==t2)ans++;
            }
        }
        cout << ans <<endl;
    }
    return 0;
}
/*
4 2
xabcx xadex
aa bb
bc de
ab cd

xabcx xadex
aaaa bbbb
*/
