#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int n,t,a1,a2,a3,ans;
vector<int> m;
//bool operator>(const vector<int>x,vector<int>y){
//
//}
int lock=-1;

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.ans", "w", stdout);
    cin>>t;
    for(int iii=0;iii<t;iii++){
        cin>>n;
        vector<vector<int> > a;
        for(int i=1;i<=n;i++){
            vector<int> vv;
            for(int ii=1;ii<=3;ii++){
                cin>>a1;
                vv.push_back(a1);
            }
            //m.push_back(max(max(vv[0],vv[1]),vv[2]));
            ans+=max(max(vv[0],vv[1]),vv[2]);
            //vv.push_back(max(max(vv[0],vv[1]),vv[2]) );
            //a.push_back(vv);
        }


//       sort(m.begin(),m.end());
//       lock=-1,ans=0;
//       int kmax,k,data[3];
//       for(int i=0;i<n;i++){
//            ans=ans+a[i][4];

            //for(int j=0;j<n;j++){
//
                //vector<int> vv=a[j];

//                if(m[i]==vv[3] && j!=lock){
//                    for(k=0;k<3;k++){
//                        if(vv[k]==vv[3]){
//                            data[k]++;
//                            if(data[k]=n/2)lock=n;
//                        }
//                    }
//                    ans+=vv[3];
//                }
//                else {
//                    for(k=0;k<3;k++){
//                        if(vv[k]==vv[3])continue;
//                        if(kmax<vv[k])kmax=vv[k];
//                    }
//                    ans+=kmax;
//                }
//




    cout<<ans<<endl;
    }

    return 0;
}
