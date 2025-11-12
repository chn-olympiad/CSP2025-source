
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<> > c1,c2,c3;
int t,n,a[N][10],s1,s2,s3,ans;
int insertc1(int l,int i){
    if(s1+1 >= n/2){
        pair<int,int> k = c1.top();
        if(l > k.first){
            c1.pop();
            c1.push({l,i});
            return k.second;
        }
        else {
            return 1e6;}
    }
    else {c1.push({l,i});s1++;}
    return 0;
}
int insertc2(int l,int i){
    if(s2+1 >= n/2){
        pair<int,int> k = c2.top();
        if(l > k.first){c2.pop();c2.push({l,i});return k.second;}
        else return 1e6;
    }
    else {c2.push({l,i});s2++;}
    return 0;
}
int insertc3(int l,int i){
    if(s3+1 >= n/2){
        pair<int,int> k = c3.top();
        if(l > k.first){c3.pop();c3.push({l,i});return k.second;}
        else return 1e6;
    }
    else {c3.push({l,i});s3++;}
    return 0;
}
int main(){
    cin >> t;
    while(t--){
        ans = s1 = s2 = s3 = 0;
        cin >> n;
        queue<int> l;
        for(int i = 1;i <= n;i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            l.push(i);
        }
        while(!l.empty()){
                cout <<1 << endl;
            int i = l.front();
            l.pop();
            int flag1 = insertc1(a[i][1],i);
            if(flag1== 1e6){
                int flag2 = insertc2(a[i][2],i);
                if(flag2 == 1e6){
                    int flag3 = insertc3(a[i][3],i);
                    if(flag3 != 0) l.push(flag3);
                }
                else if(flag2 != 0) l.push(flag2);
            }
            if(flag1 != 0){
                l.push(flag1);
            }
        }
        while(!c1.empty()){ans += c1.top().first;c1.pop();}
        while(!c2.empty()){ans += c2.top().first;c2.pop();}
        while(!c3.empty()){ans += c3.top().first;c3.pop();}
    }
}


