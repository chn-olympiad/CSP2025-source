#include<bits/stdc++.h>
using namespace std;
long long T,n,a,b,c;
int ind,ll,rr,ss;
struct Node{
    int fir,sec,thr;
};
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> p1,p2,p3,np1,np2,np3;
Node node[100100];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){

        cin>>n;

        for(int i=1;i<=n;i++){
            cin>>a>>b>>c;
            node[i].fir=a;
            node[i].sec=b;
            node[i].thr=c;
            if(a>=b and a>=c)p1.push({a,i});
            else if(b>=a and b>=c)p2.push({b,i});
            else if(c>=b and c>=a)p3.push({c,i});
        }
        //

        if(p1.size()>(n/2)){//ll->node[ind].sec   rr->node[ind].thr
            while(!p1.empty()){
                ind=p1.top().second;
                p1.pop();
                ll=node[ind].sec,rr=node[ind].thr;
                if(ll>rr)ss=abs(node[ind].fir-ll);
                else ss=abs(node[ind].fir-rr);
                np1.push({ss,ind});
            }

            while(np1.size()>(n/2)){
                ind=np1.top().second;
                np1.pop();
                ll=node[ind].sec,rr=node[ind].thr;
                if(ll>rr)p2.push({ll,ind});
                else p3.push({rr,ind});
            }
            while(!np1.empty()){
                ind=np1.top().second;
                np1.pop();
                p1.push({node[ind].fir,ind});
            }
        }


        if(p2.size()>(n/2)){//ll->node[ind].fir   rr->node[ind].thr
            while(!p2.empty()){
                ind=p2.top().second;
                p2.pop();
                ll=node[ind].fir,rr=node[ind].thr;
                if(ll>rr)ss=abs(node[ind].sec-ll);
                else ss=abs(node[ind].sec-rr);
                np2.push({ss,ind});
            }

            while(np2.size()>(n/2)){
                ind=np1.top().second;
                np2.pop();
                ll=node[ind].fir,rr=node[ind].thr;
                if(ll>rr)p1.push({ll,ind});
                else p3.push({rr,ind});
            }
            while(!np2.empty()){
                ind=np2.top().second;
                np2.pop();
                p2.push({node[ind].sec,ind});
            }
        }



        if(p3.size()>(n/2)){//ll->node[ind].fir   rr->node[ind].sec
            while(!p3.empty()){
                ind=p3.top().second;
                p3.pop();
                ll=node[ind].fir,rr=node[ind].sec;
                if(ll>rr)ss=abs(node[ind].thr-ll);
                else ss=abs(node[ind].thr-rr);
                np3.push({ss,ind});
            }

            while(np3.size()>(n/2)){
                ind=np3.top().second;
                np3.pop();
                ll=node[ind].fir,rr=node[ind].sec;
                if(ll>rr)p1.push({ll,ind});
                else p2.push({rr,ind});
            }
            while(!np3.empty()){
                ind=np3.top().second;
                np3.pop();
                p3.push({node[ind].thr,ind});
            }
        }


        long long ans=0;
        while(!p1.empty()){
            ans+=p1.top().first;
            p1.pop();
        }
        while(!p2.empty()){
            ans+=p2.top().first;
            p2.pop();
        }
        while(!p3.empty()){
            ans+=p3.top().first;
            p3.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
147325
125440
152929
150176
158541
*/
