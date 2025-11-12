#include<iostream>
using namespace std;
long long n,m,ans,e=1;
string s;
int c[1001];
int d[1001],len;
int pep[101],idd;
int pee[101],h,hii;
int suc,fai;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    len=s.length();
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        e=e*i;
    }
    for(int i=0;i<e;i++){
        idd=i;
        for(int j=1;j<=n;j++){
            pep[j]=idd%(n-j+1)+1;
            idd=idd/(n-j+1);
            pee[j]=0;
        }
        for(int j=1;j<=n;j++){
            h=0;
            hii=0;
            while(h<pep[j]){
                ++hii;
                if(pee[hii]==0) h++;
            }
            pep[j]=hii;
            pee[hii]++;
        }
        suc=0;
        fai=0;
        for(int j=1;j<=n;j++){
            if(c[pep[j]]>fai&&s[j-1]=='1'){
                suc++;
            }else{
                fai++;
            }
            if(suc>=m){
                ans++;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
