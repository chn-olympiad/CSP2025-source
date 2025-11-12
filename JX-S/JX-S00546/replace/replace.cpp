#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
string s1,s2,t1,t2,k1,k2;
int n,q,t,cnt=0;
map<string,string>d;
vector<string>v;

vector<int> detect(string ss1,string ss2){//find ss2 in ss1 (l1>l2)
    int j=0,i=0;
    bool mark=true;
    vector<int>vp;
    for(i=0;i<ss1.size();i++){
        if(ss1[i]==ss2[0] ){
            mark=true;
            for(j=i;j<i+ss2.size();j++){

                if(j>=ss1.size() || ss1[j]!=ss2[j-i] ){
                    mark=false;
                    break;
                }
            }
            if(mark==true)vp.push_back(i);
        }
    }
    return vp;
}
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.ans", "w", stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s1>>s2;
        d[s1]=s2;
        v.push_back(s1);
    }
    for(int i=0;i<q;i++){
        cin>>t1>>t2;
        cnt=0;
        for(int j=0;j<n;j++){
            s1=v[j];
            vector<int> tp=detect(t1,s1);
            if(tp.size()==0)continue;
            s2=d[s1];
            vector<int> kp=detect(t2,s2);
            if(tp.size()==0)continue;
            for(int w1 :tp){
                for(int w2:kp){
                    if(w1!=w2)continue;
                    if(t1.substr(0,w1)!=t2.substr(0,w2))continue;
                    if(t1.substr(w1+s1.size())!=t2.substr(w2+s2.size()))continue;
                    cnt++;
                    //cout<<s1<<' '<<s2<<' '<<w1<<endl;

                }
            }

        }
        cout<<cnt<<endl;

    }


    return 0;
}
