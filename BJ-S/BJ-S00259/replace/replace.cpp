#include<bits/stdc++.h>
using namespace std;
string a[205],b[205];

bool q11(int q,int st,string m,string yyy){
    string qq;
    for(int i=q;i<=st;i++){
        qq+=m[i];
    }
    int flag=1;
    for(int i=0;i<qq.size();i++){
        if(qq[i]!=yyy[i]){
            flag=0;
            break;
        }
    }
    return flag;
}
bool th(int q,int st,string y,string m,string yyy){
    string qq=y;
    for(int i=0;i<m.size();i++){
        qq[i+q]=m[i];
    }
    int flag=1;
    for(int i=0;i<qq.size();i++){
        if(qq[i]!=yyy[i]){
            flag=0;
            break;
        }
    }
    return flag;
}
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
int n,q;
cin>>n>>q;
for(int i=1;i<=n;i++){
    cin>>a[i]>>b[i];
}
while(q--){
    string y,m;
    cin>>y>>m;
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<((y.size()-a[i].size())+1);j++){
                //cout<<b[i]<<endl;
            //cout<<"!!";
            if(q11(j,j+a[i].size(),y,a[i])){
                    //cout<<"!!!";
                if(th(j,j+a[i].size(),y,b[i],m))sum++;
                //else{

                //}
            }//else{
                //cout<< a[i]<<"  ";
            //}
        }
    }
    cout<<sum<<endl;
}
return 0;
}
