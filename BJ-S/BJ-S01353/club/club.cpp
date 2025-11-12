#include<bits/stdc++.h>
#define cout1 cout
using namespace std;
int l[100001][3];
struct r{
    int i; //0 1 2
    int v; // index for l
    int sub;
    bool operator < (const r &b) const{
        return sub > b.sub;
    }
};
priority_queue<r> res0;
priority_queue<r> res1;
priority_queue<r> res2;

int ret[10];
int main(){
    ifstream ifs;
    ifs.open("club.in");
    int T;
    ifs >> T;
    ofstream ofs;
    ofs.open("club.out");
    for(int o = 0; o < T; o++){
            //cout << o <<endl;
        int n;
        ifs >> n;
        for(int i = 1; i<=n; i++){
            ifs >> l[i][0] >> l[i][1] >> l[i][2];
            if(l[i][0] >= l[i][1] && l[i][0] >= l[i][2]){
                r t;
                t.i = 0;
                t.v = i;
                t.sub = min(l[i][0] - l[i][1],l[i][0] - l[i][2]);
                res0.push(t);
                //cout1 << i << " " << 0 << endl;
            }else if(l[i][1] >= l[i][2]){
                r t;
                t.i = 1;
                t.v = i;
                t.sub = min(l[i][1] - l[i][0],l[i][1] - l[i][2]);
                res1.push(t);
                //cout1 << i << " " << 1 << endl;
            }else{
                r t;
                t.i = 2;
                t.v = i;
                t.sub = min(l[i][2] - l[i][1],l[i][2] - l[i][0]);
                res2.push(t);
                //cout1 << i << " " << 2 << endl;
            }
        }
        while(res0.size() > n/2){
            r t = res0.top();
            if(l[t.v][1] >= l[t.v][2]){
                res1.push(t);
                //cout1 << t.v << " " << 1 << endl;
            }else{
                res2.push(t);
                //cout1 << t.v << " " << 2 << endl;
            }
            res0.pop();
        }
        while(res1.size() > n/2){
            r t = res1.top();
            if(l[t.v][0] >= l[t.v][2]){
                res0.push(t);
                //cout1 << t.v << " " << 0 << endl;
            }else{
                res2.push(t);
                //cout1 << t.v << " " << 2 << endl;
            }
            res1.pop();
        }
        while(res2.size() > n/2){
            r t = res2.top();
            if(l[t.v][0] >= l[t.v][1]){
                res0.push(t);
                //cout1 << t.v << " " << 0 << endl;
            }else{
                res1.push(t);
                //cout1 << t.v << " " << 1 << endl;
            }
            res2.pop();
        }
        long long a1 = 0;
        int a2 =0 ;
        int a0 = 0;
        while(!res0.empty()){
            r it = res0.top();
            a1 += l[(it).v][0];
            res0.pop();
        }
        while(!res1.empty()){
            r it = res1.top();
            a1 += l[(it).v][1];
            res1.pop();
        }
        while(!res2.empty()){
            r it = res2.top();
            a1 += l[(it).v][2];
            res2.pop();
        }
        ret[o] = a1;
        ofs << a1 << endl;
        //cout <<res0.size() << endl << res1.size() << endl << res2.size() << endl;
    }
    memset(l,0,sizeof(l));


    return 0;
}
