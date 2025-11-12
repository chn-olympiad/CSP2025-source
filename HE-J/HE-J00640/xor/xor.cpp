#include<bits/stdc++.h>
using namespace std;


struct Node{
    int begin = 0;
    int end = 0;
    Node(int b,int e){
        begin = b;
        end = e;
    }

};

bool cmp(Node a,Node b){
    return a.end <= b.end;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    // 异或 + 前缀 + 贪心
    // 出题人的脑回路没谁了

    int n,k;
    cin >> n >> k;

    vector<int> a(n + 1,0);
    for(int i = 1;i<=n;i++) cin >> a[i];

    // 前缀和
    for(int i = 1;i<=n;i++) a[i] = a[i] ^ a[i-1];


    // 从前往后推
    vector<Node> xors;
    for(int i = 1;i<=n;i++){
        if(i==0) continue;
        for(int j = i;j<=n;j++){
            if((a[i-1]^a[j]) == k){
                Node temp(i,j);
                xors.push_back(temp);
                break;
            }
        }


    }

    sort(xors.begin(),xors.end(),cmp);

    // 以结束时间排序
    // 后以j为起始点 往遍历

    int now = -1;
    int cnt = 0;
    for(int i = 0;i<xors.size();i++){
        if(xors[i].begin <= now) continue;
        now = xors[i].end;
        cnt++;


    }

    cout << cnt;

    return 0;
}
