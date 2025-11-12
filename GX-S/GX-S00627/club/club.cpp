#include<bits/stdc++.h>
using namespace std;
class studentsm{
public:
        int st;
        int ed;
        int rd;
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    int ans=0;
    int c1,c2,c3;
    bool maxx=true;
    cin>>t;
    for(int k=0;k<t;k++){
    cin>>n;
    vector<studentsm>arr(100);
    for(int i=0;i<n;i++){
        int a1,a2,a3=0;
        cin>>a1>>a2>>a3;
        arr[i].st=a1;
        arr[i].ed=a2;
        arr[i].rd=a3;
    }
    for(int i=0;i<n;i++){
            if(arr[i].st>arr[i].ed&&arr[i].st>arr[i].rd){///////////c1max

                c1++;
                ans+=arr[i].st;}

         if(arr[i].ed>arr[i].rd&&arr[i].ed>arr[i].st){
                c2++;
                ans+=arr[i].ed;
        }
         if(arr[i].rd>arr[i].st&&arr[i].rd>arr[i].ed){
            c3++;
         ans+=arr[i].rd;
        }
    }
    cout<<ans<<"\n";
    ans=0;
    for(int i=0;i<100;i++){
        arr[i].st=0;
        arr[i].ed=0;
        arr[i].rd=0;
    }
}
    return 0;
        }
        /*#include<bits/stdc++.h>
using namespace std;
class studentsm{
public:
        int st;
        int ed;
        int rd;
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    int ans=0;
    int c1,c2,c3;
    bool maxx=true;
    cin>>t;
    for(int k=0;k<t;k++){
    cin>>n;
    vector<studentsm>arr(100);
    for(int i=0;i<n;i++){
        int a1,a2,a3=0;
        cin>>a1>>a2>>a3;
        arr[i].st=a1;
        arr[i].ed=a2;
        arr[i].rd=a3;
    }
    for(int i=0;i<n;i++){
            if(arr[i].st>arr[i].ed&&arr[i].st>arr[i].rd){///////////c1max

                c1++;
                ans+=arr[i].st;}

         if(arr[i].ed>arr[i].rd&&arr[i].ed>arr[i].st){
                c2++;
                ans+=arr[i].ed;
        }
         if(arr[i].rd>arr[i].st&&arr[i].rd>arr[i].ed){
            c3++;
         ans+=arr[i].rd;
        }
    }
    cout<<ans<<"\n";
    ans=0;
    for(int i=0;i<100;i++){
        arr[i].st=0;
        arr[i].ed=0;
        arr[i].rd=0;
    }
}
    return 0;
        }#include<bits/stdc++.h>
using namespace std;
class studentsm{
public:
        int st;
        int ed;
        int rd;
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    int ans=0;
    int c1,c2,c3;
    bool maxx=true;
    cin>>t;
    for(int k=0;k<t;k++){
    cin>>n;
    vector<studentsm>arr(100);
    for(int i=0;i<n;i++){
        int a1,a2,a3=0;
        cin>>a1>>a2>>a3;
        arr[i].st=a1;
        arr[i].ed=a2;
        arr[i].rd=a3;
    }
    for(int i=0;i<n;i++){
            if(arr[i].st>arr[i].ed&&arr[i].st>arr[i].rd){///////////c1max

                c1++;
                ans+=arr[i].st;}

         if(arr[i].ed>arr[i].rd&&arr[i].ed>arr[i].st){
                c2++;
                ans+=arr[i].ed;
        }
         if(arr[i].rd>arr[i].st&&arr[i].rd>arr[i].ed){
            c3++;
         ans+=arr[i].rd;
        }
    }
    cout<<ans<<"\n";
    ans=0;
    for(int i=0;i<100;i++){
        arr[i].st=0;
        arr[i].ed=0;
        arr[i].rd=0;
    }
}
    return 0;
        }#include<bits/stdc++.h>
using namespace std;
class studentsm{
public:
        int st;
        int ed;
        int rd;
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    int ans=0;
    int c1,c2,c3;
    bool maxx=true;
    cin>>t;
    for(int k=0;k<t;k++){
    cin>>n;
    vector<studentsm>arr(100);
    for(int i=0;i<n;i++){
        int a1,a2,a3=0;
        cin>>a1>>a2>>a3;
        arr[i].st=a1;
        arr[i].ed=a2;
        arr[i].rd=a3;
    }
    for(int i=0;i<n;i++){
            if(arr[i].st>arr[i].ed&&arr[i].st>arr[i].rd){///////////c1max

                c1++;
                ans+=arr[i].st;}

         if(arr[i].ed>arr[i].rd&&arr[i].ed>arr[i].st){
                c2++;
                ans+=arr[i].ed;
        }
         if(arr[i].rd>arr[i].st&&arr[i].rd>arr[i].ed){
            c3++;
         ans+=arr[i].rd;
        }
    }
    cout<<ans<<"\n";
    ans=0;
    for(int i=0;i<100;i++){
        arr[i].st=0;
        arr[i].ed=0;
        arr[i].rd=0;
    }
}
    return 0;
        }#include<bits/stdc++.h>
using namespace std;
class studentsm{
public:
        int st;
        int ed;
        int rd;
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    int ans=0;
    int c1,c2,c3;
    bool maxx=true;
    cin>>t;
    for(int k=0;k<t;k++){
    cin>>n;
    vector<studentsm>arr(100);
    for(int i=0;i<n;i++){
        int a1,a2,a3=0;
        cin>>a1>>a2>>a3;
        arr[i].st=a1;
        arr[i].ed=a2;
        arr[i].rd=a3;
    }
    for(int i=0;i<n;i++){
            if(arr[i].st>arr[i].ed&&arr[i].st>arr[i].rd){///////////c1max


        arr[i].ed=0;
        arr[i].rd=0;
    }
}
    return 0;
        }*/
