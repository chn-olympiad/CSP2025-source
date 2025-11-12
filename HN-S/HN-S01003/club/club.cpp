#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = (a);i<=(b);i++)
using namespace std;

//priority_queue<int,greater<int> >p1;
const int maxn = 1e5+5;

struct node{
    int first;
    int second;

    bool operator<(const node &x) const{
        return first > x.first;
    }
};

int s20cnt,s30cnt;

priority_queue<node  >q1;
priority_queue<node  >q2;
priority_queue<node >q3;
queue<int> q;
int s1[maxn],s2[maxn],s3[maxn];
int skip1[maxn],skip2[maxn],skip3[maxn];
int T,n;
long long cnt[4];
long long satis;
//join_and_push


int findDiff(int a,int b,int c){
    int maxs = max(a,max(b,c));
    int mins = min(a,min(b,c));

    if(maxs - a == 0 && mins - c == 0)return a-b;
    if(maxs - a == 0 && mins - b == 0)return a-c;
    if(maxs - b == 0 && mins - a == 0)return b-c;
    if(maxs - b == 0 && mins - c == 0)return b-a;
    if(maxs - c == 0 && mins - a == 0)return c-b;
    if(maxs - c == 0 && mins - b == 0)return c-a;

}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
            n=0;
            satis = 0;
            s20cnt =0;
            s30cnt =0;
        memset(cnt,0,sizeof(cnt));
    memset(skip1,0,sizeof(skip1));
    memset(skip2,0,sizeof(skip2));
    memset(skip3,0,sizeof(skip3));
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    memset(s3,0,sizeof(s3));
    while(!q1.empty())q1.pop();
    while(!q2.empty())q2.pop();
    while(!q3.empty())q3.pop();
        cin>>n;
        rep(i,1,n){
            scanf("%d%d%d",&s1[i],&s2[i],&s3[i]);
            q.push(i);
        }
		rep(i,1,n){
			if(s2[i] ==0) s20cnt++;
			if(s3[i] == 0)s30cnt++;
		}
		if(s30cnt == n && s20cnt == n){
			sort(s1+1,s1+n+1);
			for(int i=n;i>n/2;i--)satis+=s1[i];
			cout<<satis<<endl;
			continue;
		}
        while(!q.empty()){
            int no = q.front();
            q.pop();

            //cout<<(s1[no] > s2[no] && s1[no] > s3[no] && !skip1[no]);
        //    cout<<no;
            //cout<<(s2[no] > s1[no] && s2[no] > s3[no] );
           // cout<<s2[no]<<s3[no]<<s1[no]<<endl;

            if(s1[no] > s2[no] && s1[no] > s3[no] && cnt[1] < n/2 && !skip1[no]){
                   // cout<<no;
                int diff = findDiff(s1[no],s2[no],s3[no]);
                q1.push((node){diff,no});
                cnt[1]++;
          //      cout<<"AT1case1: +"<<s1[no]<<endl;
                satis += s1[no];
                continue;
            }else if(s1[no] > s2[no] && s1[no] > s3[no] && !skip1[no]){
//cout<<no;
                node cmpr = q1.top();

                if((cmpr.first < s1[no]) || (!skip2[no]&&cmpr.first < s1[no] + s2[cmpr.second]) || (!skip3[no]&&cmpr.first < s1[no] + s3[cmpr.second])){
                        q1.pop();
                        int diff = findDiff(s1[no],s2[no],s3[no]);
                        q1.push((node){diff,no});
                //     cout<<"AT1case2: +"<<s1[no]<<endl;
               //       cout<<"AT1case2: -"<<s1[cmpr.second]<<endl;
                        satis -= s1[cmpr.second];
                        satis+= s1[no];
                        q.push(cmpr.second);
                       skip1[cmpr.second] = 1;
            //cout<<no;
                       s1[cmpr.second] = 0;
                       continue;
                }else{
                    skip1[no] = 1;
                    s1[no] = 0;
                    q.push(no);
                    continue;
                }
               // cout<<(s2[no] > s1[no] && s2[no] > s3[no] && cnt[2] < n/2 && !skip2[no]);
                //cout<<no;
            }else if(s2[no] > s1[no] && s2[no] > s3[no] && cnt[2] < n/2 && !skip2[no]){
                int diff = findDiff(s1[no],s2[no],s3[no]);
                q2.push((node){diff,no});
                cnt[2]++;
            //  cout<<"AT2case1: +"<<s2[no]<<endl;
                satis += s2[no];
                continue;

            }else if(s2[no] > s1[no] && s2[no] > s3[no] && !skip2[no]){
              //  cout<<no;
                node cmpr = q2.top();
                if((cmpr.first < s2[no]) || (!skip1[no]&&cmpr.first < s2[no] + s1[cmpr.second]) || (!skip3[no]&&cmpr.first < s2[no] + s3[cmpr.second])){
                        q2.pop();
                        int diff = findDiff(s1[no],s2[no],s3[no]);
                        q2.push((node){diff,no});
                   //         cout<<"AT2case2: +"<<s2[no]<<endl;
                  //     cout<<"AT2case2: -"<<s2[cmpr.second]<<endl;
                        satis -= s2[cmpr.second];
                        satis+= s2[no];
                        q.push(cmpr.second);
                       skip2[cmpr.second] = 1;
                       s2[cmpr.second] = 0;
                       continue;
                }else{
                    skip2[no] = 1;
                    s2[no] = 0;
                    q.push(no);
                    continue;
                }
            }else if(s3[no] > s1[no] && s3[no] > s2[no] && cnt[3] < n/2 && !skip3[no]){
                int diff = findDiff(s1[no],s2[no],s3[no]);
                q3.push((node){diff,no});
                cnt[3]++;
             //   cout<<"AT3case1: +"<<s3[no]<<endl;
                satis += s3[no];
                continue;

            }else if(s3[no] > s1[no] && s3[no] > s2[no] && !skip3[no]){
                node cmpr = q3.top();
                if((cmpr.first < s3[no]) || (!skip2[no]&&cmpr.first < s3[no] + s2[cmpr.second]) || (!skip1[no]&&cmpr.first < s3[no] + s1[cmpr.second])){
                        q3.pop();

                                       //  cout<<"AT3case2: +"<<s3[no]<<endl;
                     //  cout<<"AT3case2: -"<<s3[cmpr.second]<<endl;
                        satis -= s3[cmpr.second];
                        satis+= s3[no];
                        q.push(cmpr.second);
                        skip3[cmpr.second] = 1;
                        s3[cmpr.second] = 0;
                        int diff = findDiff(s1[no],s2[no],s3[no]);
                        q3.push((node){diff,no});
                        continue;
                }else{
                    skip3[no] = 1;
                    q.push(no);
                    s3[no] = 0;
                    continue;
                }
            }
        }
        cout<<satis<<endl;
    }

	return 0;
}
// xuhao and val
