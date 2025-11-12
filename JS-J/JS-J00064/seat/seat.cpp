#include<fstream>
std::ifstream fin("seat.in");
std::ofstream fout("seat.out");
int n,m;
int a[101];
int main(){
    fin>>n>>m;
    for(int i=0;i<n*m;i++){
        fin>>a[i];
    }
    int sum=0;
    for(int i=0;i<n*m;i++){
        if(a[i]>=a[0]){
            sum++;
        }
    }
    fout<<(sum+n-1)/n;
    if(sum%n==0){
        fout<<" "<<n;
    }
    else{
        fout<<" "<<sum%n;
    }
}
