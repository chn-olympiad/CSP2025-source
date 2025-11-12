#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
    int fr;
    int se;
    int th;
    int cha1,cha2,cha3;
}a,b[100100];

queue<node> q;
vector<node> fir;
int mnfi=2147483647;
int sfi=0;
vector<node> sec;
int mnse=2147483647;
int sse=0;
vector<node> thr;
int mnth=2147483647;
int sth=0;
int n;
int sum=0;
bool cmp1(node a,node b){
    return a.fr>b.fr;
}
bool cmp2(node a,node b){
    return a.se>b.se;
}
bool cmp3(node a,node b){
    return a.th>b.th;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a.fr>>a.se>>a.th;
            a.cha1=abs(a.fr-a.se);
            a.cha2=abs(a.fr-a.th);
            a.cha3=abs(a.se-a.th);
            b[i]=a;
            q.push(a);
        }
        while(!q.empty()){
            node x=q.front();
            q.pop();
            if(x.fr>=x.se&&x.fr>=x.th){
                //fir.push_back(x);
                //cout<<x.fr<<endl;
                if(fir.size()+1>n/2){
                    sort(fir.begin(),fir.end(),cmp1);
                    node f=fir.back();
                    if(max(f.se,f.th)+x.fr<max(x.se,x.th)+f.fr){
                        x.fr=-999;
                        q.push(x);
                    }else if(max(f.se,f.th)+x.fr>max(x.se,x.th)+f.fr){
                        f.fr=-999;
                        q.push(f);
                        fir.pop_back();
                        fir.push_back(x);
                    }else if(min(f.th,f.se)+x.fr<min(x.th,x.se)+f.fr){
                        x.fr=-999;
                        q.push(x);
                    }else if(min(f.th,f.se)+f.fr>=min(x.th,x.se)+f.fr){
                        f.fr=-999;
                        q.push(f);
                        fir.pop_back();
                        fir.push_back(x);
                    }
                }else{
                fir.push_back(x);

                }
            }else if(x.se>=x.fr&&x.se>=x.th){
                if(sec.size()+1>n/2){
                    sort(sec.begin(),sec.end(),cmp2);
                    node f=sec.back();
                    if(max(f.fr,f.th)+x.se<max(x.fr,x.th)+f.se){
                        x.se=-999;
                        q.push(x);
                    }else if(max(f.fr,f.th)+x.se>max(x.fr,x.th)+f.se){
                        f.se=-999;
                        q.push(f);
                        sec.pop_back();
                        sec.push_back(x);
                    }else if(min(f.th,f.fr)+x.se<min(x.th,x.fr)+f.se){
                        x.se=-999;
                        q.push(x);
                    }else if(min(f.th,f.fr)+x.se>=min(x.th,x.fr)+f.se){
                        f.se=-999;
                        q.push(f);
                        sec.pop_back();
                        sec.push_back(x);
                    }
                }else{

                sec.push_back(x);
                }
            }else if(x.th>=x.se&&x.th>=x.fr){
                if(thr.size()+1>n/2){
                    sort(thr.begin(),thr.end(),cmp3);
                    node f=thr.back();
                    if(max(f.se,f.fr)+x.th<max(x.se,x.fr)+f.th){
                        x.th=-999;
                        q.push(x);
                    }else if(max(f.se,f.fr)+x.th>max(x.se,x.fr)+f.th){
                        f.th=-999;
                        q.push(f);
                        thr.pop_back();
                        thr.push_back(x);
                    }else if(min(f.fr,f.se)+x.th<min(x.fr,x.se)+f.th){
                        x.th=-999;
                        q.push(x);
                    }else if(min(f.fr,f.se)+x.th>=min(x.fr,x.se)+f.th){
                        f.th=-999;
                        q.push(f);
                        thr.pop_back();
                        thr.push_back(x);
                    }
                }else{
                    thr.push_back(x);
                }
            }
        }
        while(!fir.empty()){
            sum+=fir.back().fr;
            //cout<<fir.back().fr<<' ';
            fir.pop_back();
        }
        while(!sec.empty()){
            sum+=sec.back().se;
            //cout<<sec.back().se<<' ';
            sec.pop_back();
        }
        while(!thr.empty()){
            sum+=thr.back().th;
            //cout<<thr.back().th<<' ';
            thr.pop_back();
        }
        cout<<sum<<endl;
        sum=0;
    }

    return 0;
}
