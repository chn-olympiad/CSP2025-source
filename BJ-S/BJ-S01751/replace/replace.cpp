#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

int n,Q;
string s[5090][5];
int tl[10090][3];
int tr[10090][3];
bool f=0;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> Q;
    for(int i = 1;i <= n;i++){
        cin >> s[i][1] >> s[i][2];
    }
    if((n>1000&&Q!=1)||(n<=1000&&Q==1)){
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= s[i][1].size()-1;j++){
                if(s[i][1][j]=='b'){
                    tl[i][1]=j;
                    tr[i][1]=s[i][1].size()-1-j;
                }
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= s[i][2].size()-1;j++){
                if(s[i][2][j]=='b'){
                    tl[i][2]=j;
                    tr[i][2]=s[i][2].size()-1-j;
                }
            }
        }
        while(Q--){
            int ans=0;
            string s1,s2;
            cin >> s1 >> s2;
            int p1=-1,p2=-1;
            for(int i = 0;i <= s1.size()-1;i++){
                if(s1[i]=='b'){
                    p1=i;
                }
                if(s2[i]=='b'){
                    p2=i;
                }
            }
            //cout << p1 << " " << p2 << endl;
            for(int i = 1;i <= n;i++){
                //cout << tl[i][1] << " " << tr[i][1] << "    " << tl[i][2] << " " << tr[i][2] << endl;
                if(p1-p2!=tl[i][1]-tl[i][2]){
                    //cout << "huala" << endl;
                    continue;
                }
                if(p1>=tl[i][1]&&p2>=tl[i][2]&&s1.size()-p1-1>=tr[i][1]&&s2.size()-p2-1>=tr[i][2]){
                    ans++;
                }
            }
            cout << ans << endl;
        }
        return 0;
    }
    while(Q--){
        string s1,s2;
        cin >> s1 >> s2;
        //s1=s1+"1111111111111111";
        //s2=s2+"1111111111111111";
        int ans=0;
        int le=-1,ri=n+1;
        for(int i = 0;i <= s1.size()-1;i++){
            if(s1[i]!=s2[i]){
                ri=i;
                if(le==-1){
                    le=i;
                }
            }
        }
        for(int i = 1;i <= n;i++){
            int l=s[i][1].size();
            for(int j = 0;j <= (int)s1.size()-l;j++){
                //cout << i << " " << j << " " << l << endl;
                //cout << s1.substr(j,l) << " " << s[i][1] << endl;
                //cout << le << " " << ri << endl;
                if(s1.substr(j,l)==s[i][1]&&s2.substr(j,l)==s[i][2]&&j<=le&&ri<=j+l-1){
                    ans++;
                    //cout << "goal " << endl;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
