#include<bits/stdc++.h>
using namespace std;
struct R{
    int f,int g;
}
bool px_ls(R x,R y){
    return x.f>y.f;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.ans", "w", stdout);	
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int sum=0;
        int alen=0;
        int blen=0;
        int clen=0;
        while(n--){
            for(int i=1;i<=n;i++){
                R ls[5]={0};
            }

            for(int j=1;j<=3;j++){
                scanf("%d",&ls[j].f);
                ls[j].g=j;
            }
            sort(ls+1,ls+4,px_ls); 
            if(ls[1].g<=1&&alen<=n/2){
                alen++;
                sum+=ls[1].f;
            }else if(ls[1].g<=2&&blen<=n/2){
                blen++;
                sum+=ls[1].f;
            }else if(ls[1].g<=3&&clen<=n/2){
                clen++;
                sum+=ls[1].f;
            }else if(ls[2].g<=1&&alen<=n/2){
                alen++;
                sum+=ls[2].f;
            }
            else if(ls[2].g<=2&&blen<=n/2){
                blen++;
                sum+=ls[2].f;
            }else if(ls[2].g<=3&&clen<=n/2){
                clen++;
                sum+=ls[2].f;
            }else{
                clen--;
                
            }
            cout<<sum<<endl;
        }
  
    return 0;
}