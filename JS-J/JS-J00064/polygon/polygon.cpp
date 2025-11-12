#include<fstream>
std::ifstream fin("polygon.in");
std::ofstream fout("polygon.out");
const long long mod=998244353;
int n;
int a[5001];
int b[5001];
int main(){
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>a[i];
    }
    long long all=1;
    for(int i=n;i>=1;i--){
        all*=i;
        all%=mod;
    }
    long long choose_tow=n*(n-1)/2%mod;
    fout<<(all-choose_tow+mod)%mod;
}
