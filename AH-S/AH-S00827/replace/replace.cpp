#include<iostream>
using namespace std;
int n,q;
struct ya{
    string a,b;
}a[1000005];
string x,y;
bool A=1,B=1;//all my hope is here
int B_judge(string a){
int cnt=0,pos=0;
        for(int j=0;j<a.length();j++){
            if(a[j]=='b') cnt++,pos=j;
            if((a[j]!='b'&&a[j]!='a')||cnt>1){
                    return -1;
            }
        }
        if(!cnt) return -1;
        return pos;
}
int cnt1;//does A same AS B?//as b!
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    if(q!=1) A=0;//half of it has been away
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b;
        if(!(B_judge(a[i].a)!=-1&&B_judge(a[i].b)!=-1)){
            B=0;
        }
        if(a[i].a==a[i].b) cnt1++;//oh there is
    }
    while(q--){
        cin>>x>>y;
        if(x.length()!=y.length()){
            cout<<0<<endl;
            continue;
        }
        int posx=B_judge(x),posy=B_judge(y);
        if(posx!=-1&&posy!=-1){
            if(posx==posy){
                cout<<cnt1<<endl;
                continue;
            }
            int cntw=0;//w//
            int minpos=min(posx,posy),maxpos=max(posx,posy);
            string sa=x.substr(minpos,maxpos-minpos+1);
            string sb=y.substr(minpos,maxpos-minpos+1);//oh there is
            for(int i=1;i<=n;i++){
                int t1=a[i].a.find(sa),t2=a[i].b.find(sb),t3=x.find(a[i].a),t4=y.find(a[i].b);
                if(t3!=-1&&t4!=-1&&t1!=-1&&t2!=-1&&t1==t2){
                    cntw++;
                }
            }
            cout<<cntw<<endl;//w!
            continue;
        }
        if(x==y){
            cout<<cnt1<<endl;
            continue;
        }
        posx=-1,posy=-1;
        for(int i=0;i<x.length();i++){
            if(x[i]!=y[i]&&posx==-1){
                posx=i;
            }
            if(x[i]!=y[i]) posy=i;
        }
        int cntw=0;//it comes back!
        int minpos=min(posx,posy),maxpos=max(posx,posy);
        string sa=x.substr(minpos,maxpos-minpos+1);
        string sb=y.substr(minpos,maxpos-minpos+1);//oh there is
        for(int i=1;i<=n;i++){
            int t1=a[i].a.find(sa),t2=a[i].b.find(sb),t3=x.find(a[i].a),t4=y.find(a[i].b);
            if(t3!=-1&&t4!=-1&&t1!=-1&&t2!=-1&&t1==t2){
                cntw++;
            }
        }
        cout<<cntw<<endl;
    }
    fclose(stdin);
    fclose(stdout);//bye
    return 0;
}
