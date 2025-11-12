#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

bool a(int na1,int na2,int nb1,int nb2){
    int num = (na2-na1)+(nb1-nb2);
    if(num>0) return 1;
    else return 0;
}

int N[3][10010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,n_,rn,num = 0;cin>>t;
    while(t--){
        cin>>n;
        n_ = n/2;

        for(int i=0;i<n;i++){
            cin>>N[0][i]>>N[1][i]>>N[2][i];
        }

        for(int i=0;i<n_;i++){
            for(int j=n_;j<n;j++){
                if(a(N[0][i],N[0][j],N[1][i],N[1][j])){
                    rn = N[0][i];
                    N[0][i] = N[0][j];
                    N[0][j] = rn;

                    rn = N[1][i];
                    N[1][i] = N[1][j];
                    N[1][j] = rn;

                }
            }
        }

		num = 0;
		for(int i=0;i<n_;i++){
			num+=N[0][i];
		}

        for(int j=n_;j<n;j++){
            num+=N[1][j];
        }

        cout<<num<<endl;
    }

    return 0;
}
