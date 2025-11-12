#include<iostream>
#include<queue>
using namespace std;
const int size=1e5+9;
int a[size][3];
struct node{
    int id,num;//num:next will lose how much preference
    bool operator<(const node& _2)const{
        return num>_2.num;
    }
};
priority_queue<node>pq[3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,n,ans;
    cin>>T;
    while(T--){
        pq[0]=priority_queue<node>();
        pq[1]=priority_queue<node>();
        pq[2]=priority_queue<node>();
        ans=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            node ins={i,0};
            // if(a[i][1]>a[i][0]){
            //     ins.num=a[i][1]-a[i][0];
            // }
            // else ins.num=a[i][0]-a[i][1];
            if(a[i][2]>a[i][0]&&a[i][2]>a[i][1]){//[2] is the maximum
                // clog<<"Maximum is 2\n";
                ins.num=a[i][2]-max(a[i][1],a[i][0]);
                pq[2].push(ins);
                ans+=a[i][2];
                //check if priority_queue overloads
                if(pq[2].size()>n/2){
                    ans-=pq[2].top().num;
                    // clog<<"Popped num:"<<pq[2].top().num;
                    pq[2].pop();
                }
            }
            else if(a[i][2]>a[i][1]){//Then not bigger than a[i][0]
                // clog<<"Maximum is 0\n";
                ins.num=a[i][0]-a[i][2];
                pq[0].push(ins);
                ans+=a[i][0];
                //check if priority_queue overloads
                if(pq[0].size()>n/2){
                    ans-=pq[0].top().num;
                    // clog<<"Popped num:"<<pq[0].top().num;
                    pq[0].pop();
                }
            }
            else{
                //Then lesser than a[i][1]
                if(a[i][2]>a[i][0]){
                    // clog<<"Maximum is 1\n";
                    ins.num=a[i][1]-a[i][2];
                    pq[1].push(ins);
                    ans+=a[i][1];
                    //check if priority_queue overloads
                    if(pq[1].size()>n/2){
                        ans-=pq[1].top().num;
                        // clog<<"Popped num:"<<pq[1].top().num;
                        pq[1].pop();
                    }
                }
                else{//a[i][2] is the least
                    if(a[i][1]>a[i][0]){
                        // clog<<"Maximum is 1\n";
                        ins.num=a[i][1]-a[i][0];
                        pq[1].push(ins);
                        ans+=a[i][1];
                        //check if priority_queue overloads
                        if(pq[1].size()>n/2){
                            ans-=pq[1].top().num;
                            // clog<<"Popped num:"<<pq[1].top().num;
                            pq[1].pop();
                        }
                    }
                    else{
                        //a[i][0]>a[i][1]>a[i][2]
                        // clog<<"Maximum is 0\n";
                        ins.num=a[i][0]-a[i][1];
                        pq[0].push(ins);
                        ans+=a[i][0];
                        //check if priority_queue overloads
                        if(pq[0].size()>n/2){
                            ans-=pq[0].top().num;
                            // clog<<"Popped num:"<<pq[0].top().num;
                            pq[0].pop();
                        }
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }//Only one queue will overflow because n/2+n/2=n(n is even)
    return 0;
}//Until 18:45