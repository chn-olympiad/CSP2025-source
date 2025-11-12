#include<bits/stdc++.h>
using namespace std;
long long num[500005];
long long n,k;

bool is_xor(int a,int b){
    if(a==b){
        if(num[a]==k){
            return true;
        }
        return false;
    }
    else{
        long long sum=num[a];
        for(int i=a+1;i<=b;i++){
            sum=sum ^ num[i];
        }
        if(sum==k){
            return true;
        }
        return false;

    }
}


int main(){


    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>num[i];
    }





    long long ans=0;
    int is_over=0;
    long long now_first=1;
    for(int i=1;i<=n;i++){

        if(is_over==1){
            break;
        }
        if(now_first>n){
            break;
        }

        for(int j=now_first;j<=n;j++){


            if(now_first>n){
                now_first++;
                break;
            }


            if(is_xor(now_first,j)){
                ans++;
                now_first=j+1;

                break;
            }
            else if(j==n){
                now_first++;
                break;
            }




        }
    }


    cout<<ans;








	return 0;
}
