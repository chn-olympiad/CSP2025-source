#include<bits/stdc++.h>
using namespace std;
long long N=0,K=0,A[500010],Vis[500010],Scor;
string Era[500010],Erb;
bool In(int X,int Y){
    for(int i=X;i<=Y;i++){
        if(Vis[i]==1) return false;
    }
    return true;
}
string Change(string X,string Y){
    string Z="";
    if(X.size()<Y.size()) swap(X,Y);
    int R=X.size()-Y.size();
    for(int i=0;i<R;i++){
        Y='0'+Y;
    }
    for(int i=0;i<X.size();i++){
        if(X[i]==Y[i]) Z+='1';
        else Z+='0';
    }
    return Z;
}
int Squre(int X,int Y){
    int Cnt=0;
    for(int i=0;i<Y;i++){
        Cnt*=X;
    }
    return Cnt;
}
bool Isxor(int X,int Y){
    int Idx=1;
    for(int i=X;i<=Y;i++){
        int Cnt=A[i];
        string yu="";
        while(Cnt!=0){
            char Ch=char(X%2+'0');
            yu=yu+Ch;
        }
        Era[Idx]=yu;
        Idx++;
    }
    for(int i=1;i<Idx;i++){
        Erb=Change(Era[i],Era[i+1]);
    }
    int Ans=0;
    for(int i=Erb.size();i>=1;i--){
        Ans+=Squre(Erb[i],i-1);
    }
    if(Ans==K) return true;
    else return false;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            if(In(i,j)&&Isxor(i,j)){
                Scor++;
            }
        }
    }
    cout<<Scor;
    return 0;
}
