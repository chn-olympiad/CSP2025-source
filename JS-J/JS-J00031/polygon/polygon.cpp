#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> wood;
long long ans;
bool choosed[5];  //004
vector<vector<int>> have;
void functioN(vector<int> choose){   
    for(int i=0;i<=n-1;i++){
        if(!choosed[i]){
            choose.push_back(wood[i]);
            choosed[i]=true;    //See choose
            if(have.size()>0){
                for(int jj=0;jj<choose.size()-1;jj++){
                    if(choose[jj]>choose[jj+1]){
                    sort(choose.begin(),choose.end());
                    break;
                    }
                }
                bool same=true,in=false;
                for(int ii=0;ii<have.size();ii++){
                    if(choose.size()==have[ii].size()){
                        in=true;
                        for(int j=0;j<choose.size();j++){
                            if(choose[i]!=have[ii][i]){
                                same=false;
                                break;
                                
                            }
                        }
                    }
            }
            if(same&&in){
                choose.pop_back();
                    choosed[i]=false;
                    continue;
            }
        }
            if(choose.size()>=3){
                int maxc=choose[choose.size()-1];   // see maxc
                long long sum=0;
                for(int s=0;s<choose.size();s++){
                    sum+=choose[s];
                }
                if(sum>2*maxc){
                     
                    have.push_back(choose);
                    ans++;
                    ans%=998244353;
                    functioN(choose);   //Ans++
                    choose.pop_back();
                    choosed[i]=false;
                }
                else{
                    continue;
                }
            }
            else{
                functioN(choose);
                choose.pop_back();
                choosed[i]=false;
            }
            
        }
    }
}    //pop back one
vector<int> test;
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    if(!test.empty()){
        test.pop_back();
    }
    cin>> n ;
    for(int i=1;i<=n;i++){
        int a;
        cin>> a ;
        wood.push_back(a);
    }
    functioN(test);
    cout<< ans <<endl;
    return 0;
}