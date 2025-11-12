#include <bits/stdc++.h>
using namespace std;
struct cho{
    int w,no,n;
};
struct dif{
    int cha,from_no,to_no,n;
    friend bool operator>(dif a,dif b){
        return a.cha > b.cha;
    }
    friend bool operator<(dif a,dif b){
        return a.cha < b.cha;
    }
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector <cho> a[n];
        vector <dif> b[n];
        for(int i = 0;i < n;i++){
            cho x,y,z;
            cin>>x.w>>y.w>>z.w;
            x.no = 0;y.no = 1;z.no = 2;
            x.n = i;y.n = i;z.n = i;
            if(x.w > y.w){
                if(y.w > z.w){
                    a[i].push_back(x);
                    a[i].push_back(y);
                    a[i].push_back(z);
                }
                else{
                    if(x.w > z.w){
                        a[i].push_back(x);
                        a[i].push_back(z);
                        a[i].push_back(y);
                    }
                    else{
                        a[i].push_back(z);
                        a[i].push_back(x);
                        a[i].push_back(y);
                    }
                }
            }
            else{
                if(x.w > z.w){
                    a[i].push_back(y);
                    a[i].push_back(x);
                    a[i].push_back(z);
                }
                else{
                    if(y.w > z.w){
                        a[i].push_back(y);
                        a[i].push_back(z);
                        a[i].push_back(x);
                    }
                    else{
                        a[i].push_back(z);
                        a[i].push_back(y);
                        a[i].push_back(x);
                    }
                }
            }
            dif o,p,q;
            o.cha = a[i][0].w-a[i][1].w;
            o.from_no = a[i][0].no;
            o.to_no = a[i][1].no;
            p.cha = a[i][1].w-a[i][2].w;
            p.from_no = a[i][1].no;
            p.to_no = a[i][2].no;
            q.cha = 1e9;
            q.from_no = a[i][2].no;
            q.to_no = a[i][0].no;
            o.n = i;p.n = i;q.n = i;
            b[i].push_back(o);
            b[i].push_back(p);
            b[i].push_back(q);
        }
        int sum = 0;
        priority_queue < dif,vector <dif>,greater<dif> > pq;
        queue <dif> temp;
        int aa = 0,bb = 0,cc = 0;
        for(int i = 0;i < n;i++){
            pq.push(b[i][0]);
            sum += a[i][0].w;
            switch(b[i][0].from_no){
                case 0:
                    aa++;
                    break;
                case 1:
                    bb++;
                    break;
                case 2:
                    cc++;
                    break;
            }
            while(true){
                bool flag = 1;
                if(aa > n/2){
                    while(pq.top().from_no != 0){
                        temp.push(pq.top());
                        pq.pop();
                    }
                    switch(pq.top().from_no){
                        case 0:
                            aa++;
                            break;
                        case 1:
                            bb++;
                            break;
                        case 2:
                            cc++;
                            break;
                    }
                    pq.push(b[pq.top().n][pq.top().to_no]);
                    pq.pop();
                    sum -= pq.top().cha;
                    aa--;
                    flag = 0;
                    while(temp.size()){
                        pq.push(temp.front());
                        temp.pop();
                    }
                }
                if(bb > n/2){
                    while(pq.top().from_no != 1){
                        temp.push(pq.top());
                        pq.pop();
                    }
                    switch(pq.top().to_no){
                        case 0:
                            aa++;
                            break;
                        case 1:
                            bb++;
                            break;
                        case 2:
                            cc++;
                            break;
                    }
                    pq.push(b[pq.top().n][pq.top().to_no]);
                    pq.pop();
                    sum -= pq.top().cha;
                    bb--;
                    flag = 0;
                    while(temp.size()){
                        pq.push(temp.front());
                        temp.pop();
                    }
                }
                if(cc > n/2){
                    while(pq.top().from_no != 2){
                        temp.push(pq.top());
                        pq.pop();
                    }
                    switch(pq.top().to_no){
                        case 0:
                            aa++;
                            break;
                        case 1:
                            bb++;
                            break;
                        case 2:
                            cc++;
                            break;
                    }
                    pq.push(b[pq.top().n][pq.top().to_no]);
                    pq.pop();
                    sum -= pq.top().cha;
                    cc--;
                    flag = 0;
                    while(temp.size()){
                        pq.push(temp.front());
                        temp.pop();
                    }
                }
                if(flag) break;
            }
        }
        cout<<sum<<endl;
        while(pq.size()){
            cout<<a[pq.top().n][pq.top().from_no].w<<" ";
            pq.pop();
        }
        cout<<endl;
    }
    return 0;
}
