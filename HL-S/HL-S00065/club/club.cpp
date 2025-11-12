#include <bits/stdc++.h>

using namespace std;

int t;

struct Student{
    int a,b,c;
    int max_shuzi;
};
vector<Student> student;
unsigned long long max_renshu;
unsigned long long a_renshu,b_renshu,c_renshu;
unsigned long long res;
int n;
void dfs(int num,unsigned long long res1){
    if(a_renshu>max_renshu or b_renshu>max_renshu or c_renshu>max_renshu){
        return;
    }
    if(num>=n){
        res=max(res,res1);
        return ;
    }
    a_renshu++;
    dfs(num+1,res1+student[num].a);
    a_renshu--;
    b_renshu++;
    dfs(num+1,res1+student[num].b);
    b_renshu--;
    c_renshu++;
    dfs(num+1,res1+student[num].a);
    c_renshu--;
}
bool cmp(Student a1,Student b1){
    return a1.a>b1.a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        student.clear();
        student.resize(n);

        for(int i=0;i<n;i++){
            cin>>student[i].a;
            cin>>student[i].b;
            cin>>student[i].c;
        }
        max_renshu=n/2;
        res=0;
        a_renshu=0;
        b_renshu=0;
        c_renshu=0;
        sort(student.begin(),student.end(),cmp);
        for(int i=0;i<max_renshu;i++){
            res+=student[i].a;
        }
        cout<<res;

    }


    return 0;
}
