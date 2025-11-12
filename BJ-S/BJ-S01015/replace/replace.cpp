#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6;
typedef unsigned long long ull;
int n,q,p1=998244353,p2=1e9+7,L,R;
ull pw1[M+5],pw2[M+5];
string s1[N],s2[N],t1,t2;
vector<ull> v1[N],v2[N],v3[N],v4[N],vec1,vec2,vec3,vec4;
ull get_s1(int i,int x,int y,int c){
    if(c==1){
        return v1[i][y]-v1[i][x-1]*pw1[y-x+1];
    }
    else return v3[i][y]-v3[i][x-1]*pw2[y-x+1];
}
ull get_t1(int x,int y,int c){
    if(c==1){
        return vec1[y]-vec1[x-1]*pw1[y-x+1];
    }
    else return vec3[y]-vec3[x-1]*pw2[y-x+1];
}
ull get_t2(int x,int y,int c){
    if(c==1){
        return vec2[y]-vec2[x-1]*pw1[y-x+1];
    }
    else return vec4[y]-vec4[x-1]*pw2[y-x+1];
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    pw1[0]=pw2[0]=1;
    for(int i=1;i<=M;i++) pw1[i]=pw1[i-1]*p1;
    for(int i=1;i<=M;i++) pw2[i]=pw2[i-1]*p2;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i]; s1[i]="#"+s1[i]; s2[i]="#"+s2[i];
        int len=s1[i].size()-1; v1[i].resize(len+1); v2[i].resize(len+1);
        v3[i].resize(len+1); v4[i].resize(len+1);
        for(int j=1;j<=len;j++){
            v1[i][j]=v1[i][j-1]*p1+s1[i][j]-'a'+1;
            v2[i][j]=v2[i][j-1]*p1+s2[i][j]-'a'+1;
            v3[i][j]=v3[i][j-1]*p2+s1[i][j]-'a'+1;
            v4[i][j]=v4[i][j-1]*p2+s2[i][j]-'a'+1;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2; t1="#"+t1; t2="#"+t2;
        if(t1.size()!=t2.size()){
            cout<<0<<"\n"; continue;
        }
        int len=t1.size()-1;
        vec1.resize(len+1); vec2.resize(len+1); vec3.resize(len+1); vec4.resize(len+1);
        for(int j=1;j<=len;j++){
            vec1[j]=vec1[j-1]*p1+t1[j]-'a'+1;
            vec2[j]=vec2[j-1]*p1+t2[j]-'a'+1;
            vec3[j]=vec3[j-1]*p2+t1[j]-'a'+1;
            vec4[j]=vec4[j-1]*p2+t2[j]-'a'+1;
        }
        L=0,R=0;
        for(int j=1;j<=len;j++){
            if(t1[j]!=t2[j]){
                if(!L) L=j;
                R=j;
            }
        }
        ull val1=get_t1(L,R,1),val2=get_t1(L,R,2); int ans=0;
        for(int j=1;j<=n;j++){
            int len2=s1[j].size()-1;
            for(int k=1;k<=len2-(R-L+1)+1;k++){
                ull num1=get_s1(j,k,k+(R-L+1)-1,1),num2=get_s1(j,k,k+(R-L),2);
                if(num1==val1&&num2==val2){
                    int x=L-(k-1),y=R+len2-(k+(R-L));
                    ull tmp1=get_t1(x,y,1),tmp2=get_t2(x,y,1),tmp3=get_t1(x,y,2),tmp4=get_t2(x,y,2);
                    if(v1[j][len2]==tmp1&&v2[j][len2]==tmp2&&v3[j][len2]==tmp3&&v4[j][len2]==tmp4){
                        ++ans;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}