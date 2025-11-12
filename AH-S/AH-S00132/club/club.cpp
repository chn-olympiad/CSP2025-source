#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;

struct Data{
    int I,II,III;
}a[maxn];
struct IData{
    int I,II,III;
    bool operator>(const IData other)const{
        return (I-max(II,III)>other.I-max(other.II,other.III));
    }
};
struct IIData{
    int I,II,III;
    bool operator>(const IIData other)const{
        return (II-max(I,III)>other.II-max(other.I,other.III));
    }
};
struct IIIData{
    int I,II,III;
    bool operator>(const IIIData other)const{
        return (III-max(II,I)>other.III-max(other.II,other.I));
    }
};

int T;
int n;

priority_queue<IData,vector<IData>,greater<IData>> Iq;
priority_queue<IIData,vector<IIData>,greater<IIData>> IIq;
priority_queue<IIIData,vector<IIIData>,greater<IIIData>> IIIq;

void init(){
    cin>>n;
    priority_queue<IData,vector<IData>,greater<IData>> Iempty;
    priority_queue<IIData,vector<IIData>,greater<IIData>> IIempty;
    priority_queue<IIIData,vector<IIIData>,greater<IIIData>> IIIempty;
    swap(Iq,Iempty);
    swap(IIq,IIempty);
    swap(IIIq,IIIempty);
    // IData t1;
    // t1.I=0xfffffff;
    // t1.II=0xfffffff;
    // t1.III=0xfffffff;
    // Iq.push(t1);
    // IIData t2;
    // t2.I=0xfffffff;
    // t2.II=0xfffffff;
    // t2.III=0xfffffff;
    // IIq.push(t2);
    // IIIData t3;
    // t3.I=0xfffffff;
    // t3.II=0xfffffff;
    // t3.III=0xfffffff;
    // IIIq.push(t3);
    for(int i=1;i<=n;i++){
        cin>>a[i].I>>a[i].II>>a[i].III;
    }
}


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        init();
        for(int i=1;i<=n;i++){
            int want;
            if(a[i].I>=a[i].II && a[i].I>=a[i].III){
                if(Iq.size()<n/2){
                    IData son;
                    son.I=a[i].I;
                    son.II=a[i].II;
                    son.III=a[i].III;
                    Iq.push(son);
                    continue;
                }
                else{
                    if(a[i].I-Iq.top().I+max(Iq.top().II,Iq.top().III) > max(a[i].II,a[i].III)){
                        if(Iq.top().II>=Iq.top().III){
                            IIData top;
                            top.I=Iq.top().I;
                            top.II=Iq.top().II;
                            top.III=Iq.top().III;
                            IIq.push(top);
                        }
                        else{
                            IIIData top;
                            top.I=Iq.top().I;
                            top.II=Iq.top().II;
                            top.III=Iq.top().III;
                            IIIq.push(top);
                        }
                        Iq.pop();
                        IData son;
                        son.I=a[i].I;
                        son.II=a[i].II;
                        son.III=a[i].III;
                        Iq.push(son);
                        continue;
                    }
                    else{
                        if(a[i].II>=a[i].III){
                            IIData son;
                            son.I=a[i].I;
                            son.II=a[i].II;
                            son.III=a[i].III;
                            IIq.push(son);
                            continue;
                        }
                        else{
                            IIIData son;
                            son.I=a[i].I;
                            son.II=a[i].II;
                            son.III=a[i].III;
                            IIIq.push(son);
                            continue;
                        }
                    }
                }
                want=1;
            }
            if(a[i].II>=a[i].I && a[i].II>=a[i].III){
                if(IIq.size()<n/2){
                    IIData son;
                    son.I=a[i].I;
                    son.II=a[i].II;
                    son.III=a[i].III;
                    IIq.push(son);
                    continue;
                }
                else{
                    if(a[i].II-IIq.top().II+max(IIq.top().I,IIq.top().III) > max(a[i].I,a[i].III)){
                        if(IIq.top().I>=IIq.top().III){
                            IData top;
                            top.I=IIq.top().I;
                            top.II=IIq.top().II;
                            top.III=IIq.top().III;
                            Iq.push(top);
                        }
                        else{
                            IIIData top;
                            top.I=IIq.top().I;
                            top.II=IIq.top().II;
                            top.III=IIq.top().III;
                            IIIq.push(top);
                        }
                        IIq.pop();
                        IIData son;
                        son.I=a[i].I;
                        son.II=a[i].II;
                        son.III=a[i].III;
                        IIq.push(son);
                        continue;
                    }
                    else{
                        if(a[i].I>=a[i].III){
                            IData son;
                            son.I=a[i].I;
                            son.II=a[i].II;
                            son.III=a[i].III;
                            Iq.push(son);
                            continue;
                        }
                        else{
                            IIIData son;
                            son.I=a[i].I;
                            son.II=a[i].II;
                            son.III=a[i].III;
                            IIIq.push(son);
                            continue;
                        }
                    }
                }
                want=2;
            }
            if(a[i].III>=a[i].I && a[i].III>=a[i].II){
                if(IIIq.size()<n/2){
                    IIIData son;
                    son.I=a[i].I;
                    son.II=a[i].II;
                    son.III=a[i].III;
                    IIIq.push(son);
                    continue;
                }
                else{
                    if(a[i].III-IIIq.top().III+max(IIIq.top().I,IIIq.top().II) > max(a[i].I,a[i].II)){
                        if(IIIq.top().I>=IIIq.top().II){
                            IData top;
                            top.I=IIIq.top().I;
                            top.II=IIIq.top().II;
                            top.III=IIIq.top().III;
                            Iq.push(top);
                        }
                        else{
                            IIData top;
                            top.I=IIIq.top().I;
                            top.II=IIIq.top().II;
                            top.III=IIIq.top().III;
                            IIq.push(top);
                        }
                        IIIq.pop();
                        IIIData son;
                        son.I=a[i].I;
                        son.II=a[i].II;
                        son.III=a[i].III;
                        IIIq.push(son);
                        continue;
                    }
                    else{
                        if(a[i].I>=a[i].II){
                            IData son;
                            son.I=a[i].I;
                            son.II=a[i].II;
                            son.III=a[i].III;
                            Iq.push(son);
                            continue;
                        }
                        else{
                            IIData son;
                            son.I=a[i].I;
                            son.II=a[i].II;
                            son.III=a[i].III;
                            IIq.push(son);
                            continue;
                        }
                    }
                }
                want=3;
            }
        }
        int ans=0;
        for(;!Iq.empty();){
            ans+=Iq.top().I;
            Iq.pop();
        }
        for(;!IIq.empty();){
            ans+=IIq.top().II;
            IIq.pop();
        }
        for(;!IIIq.empty();){
            ans+=IIIq.top().III;
            IIIq.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}