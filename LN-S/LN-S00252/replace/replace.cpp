#include<iostream>
#include<cstring>
#include<map>
using namespace std;
map<string,string> dict;
int n,q;
char s[500005],s2[500005];
string sA,s2A,sAtmp;
int xend,zbegin;
string x,y,z;
int ans;
void getxz(){
    int l=strlen(s);
    for(xend=0;xend<l;xend++){
        if(s[xend]!=s2[xend]){
            xend--;
            break;
        }
    }
    if(xend==l-1){
        zbegin=0;
        return;
    }
    for(zbegin=0;zbegin<l;zbegin++){
        if(s[zbegin]!=s2[zbegin]){
            zbegin--;
            break;
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    //s[i~j]: s.substr(i,j-i+1);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%s%s",s,s2);
        dict[string(s)]=string(s2);
    }
    for(int i=1;i<=q;i++){
        scanf("%s%s",s,s2);
        //cout<<"--------------------------"<<i<<"---------------------------\n";
        getxz();
        for(auto j:dict){
            sA=string(s);
            s2A=string(s2);
            sAtmp=string(s);
            y=j.first;
            while(sA.find(y)!=string("").find("a")){
                //cout<<sA.find(y)<<" sA:"<<sA<<" y:"<<y<<"\n";
                if(sA.find(y)>xend+1 || sA.find(y)+y.size()-1<zbegin-1){
                    s2A[sA.find(y)]='!';
                    sA[sA.find(y)]='!';
                    continue;
                }
                if(sA.replace(sA.find(y),y.size(),j.second)==s2A){
                    ans++;
                    //cout<<j.first<<" "<<j.second<<"\n";
                    break;
                }else{
                    sA=sAtmp;
                    //cout<<sA.find(y)<<" sA:"<<sA<<" y:"<<y<<"\n";
                    s2A[sA.find(y)]='!';
                    sA[sA.find(y)]='!';
                }
            }
        }
        printf("%d\n",ans);
        ans=0;
    }
    return 0;
}
