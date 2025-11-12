#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;

    vector<string> ss1(1,""),ss2(1,"");
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        ss1.push_back(s1);
        ss2.push_back(s2);
    }

    vector<vector<string>> dif1,dif2;
    vector<int> dn,ct;
    for(int i=1;i<=n;i++){
        string tmps1,tmps2;
        bool sw=(ss1[i][0]==ss2[i][0]);
        vector<string> tmpv1(1,""),tmpv2(1,"");
        int tmp=1,cnt=0;
        for(int p=0;p<ss1[i].size();p++){
            if(((sw==0&&ss1[i][p]==ss2[i][p])||(sw==1&&ss1[i][p]!=ss2[i][p]))){
                tmpv1.push_back(tmps1);
                tmps1="";
                tmpv2.push_back(tmps2);
                tmps2="";
                sw^=1;
                tmp++;
            }
            tmps1.push_back(ss1[i][p]);
            tmps2.push_back(ss2[i][p]);
        }
        tmpv1.push_back(tmps1);
        tmpv2.push_back(tmps2);
        dif1.push_back(tmpv1);
        dif2.push_back(tmpv2);
        dn.push_back(tmp);
        for(int j=1;j<=tmp;j++)
            if(dif1[i-1][j]!=dif2[i-1][j])cnt++;
        ct.push_back(cnt);
        /*
        for(auto s : tmpv1)cout<<s<<' ';
        cout<<'\n';
        for(auto s : tmpv2)cout<<s<<' ';
        cout<<'\n';
        */
    }

    while(q--){
        string S1,S2;
        cin>>S1>>S2;
        if(S1.size()!=S2.size()){
            cout<<0<<'\n';
            continue;
            //return 0;
        }

        string tmps1,tmps2;
        bool sw=(S1[0]==S2[0]);
        vector<string> Dif1(1,""),Dif2(1,"");
        int Dn=1,goal=0;
        for(int p=0;p<S1.size();p++){
            if((sw==0&&S1[p]==S2[p])||(sw==1&&S1[p]!=S2[p])){
                Dif1.push_back(tmps1);
                tmps1="";
                Dif2.push_back(tmps2);
                tmps2="";
                sw^=1;
                Dn++;
            }
            tmps1.push_back(S1[p]);
            tmps2.push_back(S2[p]);
        }
        Dif1.push_back(tmps1);
        Dif2.push_back(tmps2);
        for(int i=1;i<=Dn;i++)
            if(Dif1[i]!=Dif2[i])goal++;
        /*
        for(auto s : Dif1)cout<<s<<' ';
        cout<<'\n';
        for(auto s : Dif2)cout<<s<<' ';
        cout<<'\n';
        */
        int ans=0;
        for(int i=0;i<n;i++){
            if(dn[i]>Dn||ct[i]<goal)continue;
            //cout<<dn[i]<<' '<<Dn<<'\n';
            bool flag=0;
            for(int j=1;j+dn[i]-1<=Dn;j++){
                bool flagg=1;
                for(int k=j;k<=j+dn[i]-1;k++){
                    if(dif1[i][k-j+1]!=Dif1[k]||dif2[i][k-j+1]!=Dif2[k])flagg=0;
                    //cout<<dif1[i][k-j+1]<<' '<<dif2[i][k-j+1]<<' '<<Dif1[k]<<' '<<Dif2[k]<<'\n';
                }
                flag|=flagg;
            }
            if(flag)ans++;
        }
        cout<<ans<<'\n';
    }
}
