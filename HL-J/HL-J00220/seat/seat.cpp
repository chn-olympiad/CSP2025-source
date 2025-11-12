#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*
CSP-J 2025 第二轮正在进行。小R 所在的考场共有n ×m 名考生，其中所有考生
的 CSP-J 2025 第一轮成绩互. 不. 相. 同. 。所有 n × m 名考生将按照 CSP-J 2025 第一轮的
成绩，由. 高. 到. 低. 蛇. 形. 分. 配. 座位，排列成 n 行. m 列. 。具体地，设小 R 所在的考场的所有
考生的成绩从. 高. 到. 低. 分别为 s1 > s2 > · · · > sn×m，则成绩为s1 的考生的座位为第 1 列.
第 1 行. ，成绩为 s2 的考生的座位为第 1 列. 第 2 行. ，……，成绩为 sn 的考生的座位为
第 1 列. 第 n 行. ，成绩为 sn+1 的考生的座位为第 2 列. 第 n 行. ，……，成绩为 s2n 的考生
的座位为第 2 列. 第 1 行. ，成绩为 s2n+1 的考生的座位为第 3 列. 第 1 行. ，以此类推。
例如，若n = 4，m = 5，则所有4 × 5 = 20 名考生将按照CSP-J 2025 第一轮成绩
从高到低的顺序，根据下图中的箭头顺序蛇形分配座位。
*/
vector<ll> bubble(vector<ll> vec,ll length){
    vec.resize(length);
    for(ll i=0;i<length;i++){
        for(ll j=i+1;j<length;j++){
            ll tmp=0;
            if(vec[j]<vec[i]){
                tmp=vec[i];
                vec[i]=vec[j];
                vec[j]=tmp;
            }
        }
    }

    return vec;
}
ll sch(vector<ll> vec,ll val){
    for(ll i=0;i<vec.size();i++){
        if(vec[i]==val){
            return i;
        }
    }
    return -1;
}
int main(){
    freopen("seat.out","w",stdout);
    freopen("seat.in","r",stdin);

    ll col,row,wc,wr;
    vector<ll> scores;
    vector<ll> grades;
    cin>>row>>col;
    scores.resize(row*col);
    for(ll i=0;i<scores.size();i++){
        cin>>scores[i];
    }
    ll R=scores[0];
    //for(int i=0;i<scores.size();i++){
    //    cout<<scores[i]<<' ';
    //}
    scores=bubble(scores,scores.size());
    //for(int i=0;i<scores.size();i++){
    //    cout<<scores[i]<<' ';
    //}
    ll R_grade=sch(scores,R);
    vector<ll> range;

    for(ll i=0;i<col;){
        for(ll j=row;j>0;j--){
            range.insert(range.begin(),j);
        }
        i++;
        if(i>=col)break;

        for(ll j=1;j<=row;j++){
            range.insert(range.begin(),j);
        }
        i++;
    }

    wc=range[(R_grade/row+1)*row];
    wr=R_grade%row;

    cout<<wc<<' '<<wr;

    return 0;
}
