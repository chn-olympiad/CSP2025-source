#include <bits/stdc++.h>
using namespace std;
int all=0;
int aid=0;
struct club{
    int s1;
    int s2;
    int s3;
}a[6][100005];
int p[6];
int cnt[100005];
int group;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;//总组数
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> group;
        p[i]=group;
        for(int j=1;j<=group;j++){
            cin>>a[i][j].s1>>a[i][j].s2>>a[i][j].s3;
            all++;
        }
    }
    //开始处理数据
    int ag[6];

    int m = all/2;
    for(int i=1;i<=t;i++){
        ag[i]=0;
        for(int j=1;j<=p[i];j++){
            aid++;
            cnt[aid]=max(max(a[i][j].s1,a[i][j].s2),a[i][j].s3);
            ag[i]+=cnt[aid];
        }
    }
    int answer=0;
    for(int i=1;i<=aid;i++){
        answer+=cnt[i];
    }
    //测试输入
    //for(int i=1;i<=id;i++){
    //    cout<<a[i].s1<<" "<<a[i].s2<<" "<<a[i].s3<<endl;
    //}
    //测试结束

    //cout<<answer<<endl;
    for(int i=1;i<=t;i++){
        cout<<ag[i]<<endl;
    }

    return 0;
}
