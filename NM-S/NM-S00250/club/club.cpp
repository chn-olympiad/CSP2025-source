#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,t,num[4],ans,muda[4],check[5];
priority_queue<ll> qa,qb,qc;
queue<ll> q4;
void init(){
    while(!qa.empty()){
        qa.pop();
    }
    while(!qb.empty()){
        qb.pop();
    }
    while(!qc.empty()){
        qc.pop();
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld%",&t);
    while(t--){
        scanf("%lld%",&n);
        memset(num,0,sizeof(num));
        memset(muda,0,sizeof(muda));
        memset(check,0,sizeof(check));
        init();
        ans=0;
        for(int i=1;i<=n;i++){
            ll a,b,c,vis=0;
            scanf("%lld%lld%lld",&a,&b,&c);
            if(a==0){
                a=muda[1];
                vis=1;
                check[1]=1;
            }
            if(b==0){
                b=muda[2];
                vis=1;
                check[2]=2;
            }
            if(c==0){
                c=muda[3];
                vis=1;
                check[3]=3;
            }
            if(vis==1){
                if(a+b+c<=muda[0]){
                    for(int i=1;i<=3;i++){
                        if(check[1]){
                            a=0;
                            check[1]=0;
                        }
                        if(check[2]){
                            b=0;
                            check[2]=0;
                        }
                        if(check[3]){
                            c=0;
                            check[3]=0;
                        }
                    }
                }
                else{
                    if(check[0]==1){
                        for(int i=1;i<=qa.size();i++){
                            ll temp=qa.top();
                            q4.push(temp);
                            qa.pop();
                        }
                        for(int i=1;i<=q4.size();i++){
                            if(q4.front()==muda[0]){
                                q4.pop();
                            }
                            ll temp=q4.front();
                            q4.pop();
                            q4.push(temp);
                        }
                        for(int i=1;i<=q4.size();i++){
                            ll temp=q4.front();
                            qa.push(temp);
                            q4.pop();
                        }
                    }
                    else if(check[0]==2){
                        for(int i=1;i<=qb.size();i++){
                            ll temp=qb.top();
                            q4.push(temp);
                            qb.pop();
                        }
                        for(int i=1;i<=q4.size();i++){
                            if(q4.front()==muda[0]){
                                q4.pop();
                            }
                            ll temp=q4.front();
                            q4.pop();
                            q4.push(temp);
                        }
                        for(int i=1;i<=q4.size();i++){
                            ll temp=q4.front();
                            qb.push(temp);
                            q4.pop();
                        }
                    }
                    else if(check[0]==3){
                        for(int i=1;i<=qc.size();i++){
                            ll temp=qc.top();
                            q4.push(temp);
                            qc.pop();
                        }
                        for(int i=1;i<=q4.size();i++){
                            if(q4.front()==muda[0]){
                                q4.pop();
                            }
                            ll temp=q4.front();
                            q4.pop();
                            q4.push(temp);
                        }
                        for(int i=1;i<=q4.size();i++){
                            ll temp=q4.front();
                            qc.push(temp);
                            q4.pop();
                        }
                    }
                    for(int i=1;i<=3;i++){
                        if(check[1]){
                            a=0;
                            check[1]=0;
                        }
                        if(check[2]){
                            b=0;
                            check[2]=0;
                        }
                        if(check[3]){
                            c=0;
                            check[3]=0;
                        }
                    }
                    ll y=max({muda[1],muda[2],muda[3]});
                    if(y==muda[1]){
                        y=max(muda[2],muda[3]);
                        if(y==muda[2]){
                            qb.push(y);
                            check[0]=0;
                        }
                        else if(y==muda[3]){
                            qc.push(y);
                            check[0]=0;
                        }
                    }
                    else if(y==muda[2]){
                        y=max(muda[1],muda[3]);
                        if(y==muda[1]){
                            qa.push(y);
                            check[0]=0;
                        }
                        else if(y==muda[3]){
                            qc.push(y);
                            check[0]=0;
                        }
                    }
                    else if(y==muda[3]){
                        y=max(muda[2],muda[1]);
                        if(y==muda[2]){
                            qb.push(y);
                            check[0]=0;
                        }
                        else if(y==muda[1]){
                            qa.push(y);
                            check[0]=0;
                        }
                    }
                }
            }
            ll temp=max({a,b,c});
            if(temp==a){
                qa.push(a);
                check[0]=1;
            }
            else if(temp==b){
                qb.push(b);
                check[0]=2;
            }
            else if(temp==c){
                qc.push(c);
                check[0]=3;
            }
            muda[1]=a;
            muda[2]=b;
            muda[3]=c;
            muda[0]=temp;

        }
/*
        while(!qb.empty()){
            ll temp=qb.top();
            printf("%lld\n",temp);
            qb.pop();
        }
*/
        for(int i=1;i<=n;i++){
            while(num[1]<(n/2)&&!qa.empty()){
                ans+=qa.top();
                qa.pop();
                num[1]++;
            }
            while(num[2]<(n/2)&&!qb.empty()){
                ans+=qb.top();
                qb.pop();
                num[2]++;
            }
            while(num[3]<(n/2)&&!qc.empty()){
                ans+=qc.top();
                qc.pop();
                num[3]++;
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}

