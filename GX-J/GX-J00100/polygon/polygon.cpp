#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> len;

bool isPolygon(unsigned long long c){
    unsigned long long sum=0;
    int max_number=0;
    int use=0;
    int index=0;
    while(c&&index<n){
        if(c&1){
            ++use;
            sum+=len[index];
            max_number=len[index];
            ++index;
        }
        c>>=1;
    }
    if(use>=3)
        return sum>max_number*2;
    else
        return false;
}

bool sortRule(int a,int b){
    return a>b;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }

    len.resize(n);
    for(int i=0;i<n;++i)
        cin>>len[i];

    int answer=0;
    unsigned long long c=0;
    while(c<1<<n&&c<=LONG_MAX){
        answer+=(int)isPolygon(c);
        ++c;
    }

    cout<<answer;

    return 0;
}
