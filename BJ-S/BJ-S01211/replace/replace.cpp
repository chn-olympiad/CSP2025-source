#include<bits/stdc++.h>
using namespace std;

const int N=200009;
int n,q;

//int getb(string a){
//    for(int i=0;i<a.size();i++){
//        if(a[i]=='b'){
//            return i;
//        }
//    }
//}
string s1[N],s2[N];
string t1[N],t2[N];
int l1=0,l2=0;

void solve12(int i) {
    int cnt=0;
    if(t1[i].size()!=t2[i].size()) {
        cout<<0<<endl;
        return;
    }
    for(int j=1;j<=n;j++){//模式
        for(int i1=0;i1<t1[i].size();i1++){
            bool flag=true; //能否替换
            for(int j1=0;j1<s1[j].size();j1++){
                if (t1[i][i1+j1]!=s1[j][j1]){
                    flag=false;
                    break;
                }
            }
            if(!flag) continue;//不替换不可能

            bool tihuan=true;//是否成功
            //替换逻辑
            for(int j1=0;j1<t1[i].size();j1++){
                if(i1<=j1 && j1<i1+s1[j].size()){
                    //替换该字符
                    //cout<<"aa"<<endl;
                    if(t2[i][j1] != s2[j][j1-i1]) {
                        tihuan=false;
                        break;
                    }
                } else{
                    //不替换
                    if(t1[i][j1] != t2[i][j1]) {
                        tihuan=false;
                        break;
                    }
                }
            }
            if(tihuan) {
                //cout<<t1[i]<<":"<<s1[j]<<"->"<<s2[j]<<"="<<t2[i]<<endl;
            }
            cnt+=tihuan;
        }
    }
    cout<<cnt<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        l1+=s1[i].size()+s2[i].size();
    }
    for(int i=1;i<=q;i++){
        cin>>t1[i]>>t2[i];
        l2+=t1[i].size()+t2[i].size();
    }

        for(int i=1;i<=q;i++){
            solve12(i);
        }
        return 0;



    return 0;
}
