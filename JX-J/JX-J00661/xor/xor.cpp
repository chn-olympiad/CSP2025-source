#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int arr[N];
struct lr{
    int l;
    int r;
};
vector<lr> vec;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j&&i==k){
                    bool flag=true;
                    if(!vec.empty()){
                        for(int it=0;it<vec.size();it++){
                            if(!(vec[it].l>i||vec[it].r<i)){
                                flag=false;
                                break;
                            }
                        }
                    }
                    if(flag){
                            lr temp1={i,j};
                        vec.push_back(temp1);
                    }
            }
            else{
                int sum=arr[i];
            for(int ik=i+1;ik<=j;ik++){
                sum=sum^arr[ik];
            }
            if(sum==k){
                bool flag=true;
                    if(!vec.empty()){
                        for(int it=0;it<vec.size();it++){
                                if(i<vec[it].l&&j>vec[it].r||j<vec[it].l&&i>vec[it].r){
                                    for(int jixu=vec[it].l;jixu<=vec[it].r;jixu++){
                                if(jixu==i||jixu==j){
                                    flag=false;
                                    break;
                                }
                            }
                            break;
                                }
                                else{
                                    flag=false;
                                    break;
                                }

                        }
                    }
                    if(flag){
                            if(i<j){
                                lr temp2={i,j};
                                vec.push_back(temp2);
                            }
                            else{
                                lr temp2={i,j};
                                vec.push_back(temp2);
                            }

                    }
            }
            }
        }
    }
    cout<<vec.size();
    return 0;
}
