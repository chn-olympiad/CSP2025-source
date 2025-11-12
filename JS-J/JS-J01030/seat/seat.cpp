#include<fstream>
#include<algorithm>
using namespace std;
long long n,m,a[105],s;
bool cmp(long long x,long long y){
    return x > y;
}
int main(){
    ifstream fin("seat.in");
    ofstream fout("seat.out");
    fin >> n >> m;
    for(int i = 1;i <= n*m;i++){
        fin >> a[i];
    }
    s = a[1];
    sort(a+1,a+n*m+1,cmp);
    long long tmp = 1;
    for(int i = 1;i <= m;i++){
        if(i % 2 == 1){
            for(int j = 1;j <= n;j++){
                if(a[tmp++] == s){
                    fout << i <<" "<< j;
                    return 0;
                }
            }
        }else{
            for(int j = n;j >= 1;j--){
                if(a[tmp++] == s){
                    fout << m <<" "<<n;
                    return 0;
                }
            }
        }
    }
    return 0;
}
