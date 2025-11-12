#include<bits/stdc++.h>
using namespace std;
struct stu{
    int score;
    bool flg=0;
};
bool cmp(stu a,stu b){
    return a.score>b.score;
}
int main (){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<stu>student;
    for(int i=1;i<=n*m;i++){
        stu f={0,false};
        int s;cin>>s;
        f.score=s;
        student.push_back(f);
    }
    student[0].flg=true;
    sort(student.begin(),student.end(),cmp);
    int ans;

 //   for(auto a:student){
 //       cout<<a.score<<" ";
 //   }

    for(int i=0;i<student.size();i++){
        if(student[i].flg){
            ans=i;
            break;
        }
    }
   //     cout<<ans<<" "<<ans%n<<" "<<n<<endl;
    cout<< ans/n+1 <<" " ;
    if((ans/n+1)%2==0){
            int f=n-(ans%n);
        cout<<f;
    }else cout<<ans%n+1;
    return 0;
}
