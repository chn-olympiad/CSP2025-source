#include<bits/stdc++.h>
using namespace std;
int mum1,mum2,mum3,t,n,ans,n1;
struct student{
    int x,y,z;
};
vector<int > c1,c2,c3;
student stu[100005];
vector<int > studen;
int main(){
    cin>>t;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    while(t--){
        mum1=mum2=mum3=ans=n=n1=0;
        c1.clear();
        c2.clear();
        c3.clear();
        studen.clear();
        cin>>n;


        for(int i=1;i<=n;i++){

            int x,y,z;
            cin>>x>>y>>z;
            stu[i].x=x;
            stu[i].y=y;
            stu[i].z=z;
            if(x>=y&&x>=z){
                c1.push_back(i);
            }else if(y>x&&y>=z){
                c2.push_back(i);
            }else{
                c3.push_back(i);
            }

        }
        sort(c1.begin(),c1.end());
        sort(c2.begin(),c2.end());
        sort(c3.begin(),c3.end());
        while(!c1.empty()){
            if(mum1==n/2) break;
            ans+=stu[c1[c1.size()-1]].x;
            c1.pop_back();
            mum1++;
        }
        while(!c2.empty()){
            if(mum2==n/2) break;
            ans+=stu[c2[c2.size()-1]].y;
            c2.pop_back();
            mum2++;
        }
        while(!c1.empty()){
            if(mum3==n/2) break;
            ans+=stu[c3[c3.size()-1]].z;
            c3.pop_back();
            mum3++;
        }
        while(!c1.empty()){
            studen.push_back(c1[c1.size()-1]);
            c1.pop_back();
        }
        while(!c2.empty()){
            studen.push_back(c2[c2.size()-1]);
            c2.pop_back();
        }
        while(!c3.empty()){
            studen.push_back(c3[c3.size()-1]);
            c3.pop_back();
        }
        for(int i=0;i<studen.size();i++){
            if(mum1==n/2)ans+=max(stu[studen[i]].y,stu[studen[i]].z);
            else if(mum2==n/2)ans+=max(stu[studen[i]].x,stu[studen[i]].z);
            else ans+=max(stu[studen[i]].x,stu[studen[i]].y);
        }
        cout<<ans<<endl;
    }
}

