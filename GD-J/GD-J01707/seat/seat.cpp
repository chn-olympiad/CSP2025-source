#include <bits/stdc++.h>
using namespace std;

int m,n,a,s[107],sum,resn=1,resm=1,f=1;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    sum=m*n;
    for(int i=0;i<sum;i++){
        cin>>s[i];
    }
    a=s[0];
    sort(s,s+m*n);

    for(int i=sum-1;i>=0;i--){
        if(s[i]==a){
            cout<<resm<<' '<<resn<<endl;
            return 0;
        }
        if(f==1){
            if(resn+1<=n)resn++;
            else {
                resm++;
                f=2;
            }
        }
        else if(f==2){
            if(resn-1>=1)resn--;
            else {
                resm++;
                f=1;
            }
        }
    }
    fclose(stdin);
	fclose(stdout); 
    return 0;
}
