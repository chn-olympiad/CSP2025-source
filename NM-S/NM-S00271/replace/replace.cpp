#include<iostream>
#include<cstring>
using namespace std;

typedef pair<string,string>PII;

string replace1(string s_0,PII s_,int i){
    string s_1=s_0;
    for(int j=i;j<i+(s_.second).size();j++){
        if(s_0[j]!=(s_.first)[j-i]){
            return "";
        }
        s_1[j]=(s_.second)[j-i];
    }
    return s_1;
}

const int MAXSIZE=2e5+10;
int N,Q;
PII sdata[MAXSIZE];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    string temp1,temp2;
    cin>>N>>Q;
    for(int i=0;i<N;i++){
        cin>>temp1>>temp2;
        sdata[i]={temp1,temp2};
    }
    while(Q){
        int cnt=0;
        cin>>temp1>>temp2;
        for(int i=0;i<N;i++){
            int t1s=temp1.size(),d1s=(sdata[i].first).size();
            if(t1s<d1s) continue;
            for(int j=0;j<=t1s-d1s;j++){
               if (replace1(temp1,sdata[i],j)==temp2) cnt++;
            }
        }
        printf("%d\n",cnt);
        Q--;
    }
    fclose(stdin);
    fclose(stdout);
}
