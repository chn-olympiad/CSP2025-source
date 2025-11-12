#include<fstream>
using namespace std;
long long n,k,a[500005];
int main(){
    ifstream fin("xor.in");
    ofstream fout("xor.out");
    fin >> n >> k;
    for(int i = 1;i <= n;i++){
        fin >> a[i];
    }
    long long tmp1 = 0;
    long long tmp2 = 0;
    for(int i = 1;i <= n;i++){
        if(a[i] == 0){
            tmp1++;
        }else if(a[i] == 1){
            tmp2 ++;
        }
    }
    if(k == 0) fout << tmp1+tmp2/2;
    else if(k == 1) fout << tmp2+tmp1/2;
    return 0;
}
