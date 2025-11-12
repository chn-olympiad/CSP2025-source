#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Node{
    int type;
    int x;
    bool operator<(Node& b){
        return x<b.x;
    }
};

struct Student{
    Node node[3];
    bool operator<(Student& b){
        return node[0]<b.node[0];
    }
};

int T,n,cnt[5],sum;
Student a[100005];


void func(Student& s){
    if(s.node[0]<s.node[1]){
        swap(s.node[0],s.node[1]);
    }
    if(s.node[0]<s.node[2]){
        swap(s.node[0],s.node[2]);
    }
    if(s.node[1]<s.node[2]){
        swap(s.node[1],s.node[2]);
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        sum=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                a[i].node[j].type=j;
                cin>>a[i].node[j].x;
                func(a[i]);
            }

        }
        for(int i=0;i<3;i++){
            cnt[i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                cout<<a[i].node[j].type<<" "<<a[i].node[j].x<<" ";
            }
            cout<<"\n";
        }
        sort(a+1,a+n+1);
        for(int i=n;i>=1;i--){
            for(int j=0;j<3;j++){
                if(cnt[a[i].node[j].type]<n/2){
                    sum+=a[i].node[j].x;
                    cnt[a[i].node[j].type]++;
                    break;
                }
            }
        }
        cout<<sum;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}