#include <bits/stdc++.h>
int t,n,in1,in2,in3;
struct p{
    int v1;
    int v2;
    int v3;
};
bool operator<(p p1,p p2) {
    int diff1_max = std::min(p1.v1-p1.v2,p1.v1-p1.v3);
    int diff1_min = std::max(p1.v1-p1.v2,p1.v1-p1.v3);
    int diff2_max = std::min(p2.v1-p2.v2,p2.v1-p2.v3);
    int diff2_min = std::max(p2.v1-p2.v2,p2.v1-p2.v3);
    if(diff1_max != diff2_max) {
        return diff1_max > diff2_max;
    }
    return diff1_min > diff2_min;
}
std::priority_queue<p> q1;
std::priority_queue<p> q2;
std::priority_queue<p> q3;
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin>>t;
    while(t--) {
        int sum = 0;
        std::cin>>n;
        for(int i = 0;i < n;i++) {
            std::cin>>in1>>in2>>in3;
            if(in1 >= in2 && in1 >= in3) {
                q1.push({in1,in2,in3});
            }
            else if(in2 >= in3 && in2 >= in1) {
                q2.push({in2,in1,in3});
            }
            else {
                q3.push({in3,in1,in2});
            }
        }
        while(q1.size() > n/2) {
            p front = q1.top();
            q1.pop();
            if(front.v2 > front.v3) {
                q2.push({front.v2,front.v1,front.v3});
            }
            else {
                q3.push({front.v3,front.v1,front.v2});
            }
        }
        while(q2.size() > n/2) {
            p front = q2.top();
            q2.pop();
            if(front.v2 > front.v3) {
                q1.push({front.v2,front.v1,front.v3});
            }
            else {
                q3.push({front.v3,front.v2,front.v1});
            }
        }
        while(q3.size() > n/2) {
            p front = q3.top();
            q3.pop();
            if(front.v2 > front.v3) {
                q1.push({front.v2,front.v3,front.v1});
            }
            else {
                q2.push({front.v3,front.v2,front.v1});
            }
        }
        while(!q1.empty()) {
            sum += q1.top().v1;
            q1.pop();
        }
        while(!q2.empty()) {
            sum += q2.top().v1;
            q2.pop();
        }
        while(!q3.empty()) {
            sum += q3.top().v1;
            q3.pop();
        }
        std::cout<<sum<<"\n";
    }
    return 0;
}
