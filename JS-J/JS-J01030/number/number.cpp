#include<fstream>
#include<string>
using namespace std;
string a;
long long b[15];
int main(){
    ifstream fin("number.in");
    ofstream fout("number.out");
    fin >> a;
    for(int i = 0;i < a.size();i++){
        if(a[i] >= '0' && a[i] <= '9'){
            long long tmp = a[i] - '0';
            b[tmp] ++;
        }
    }
    for(int i = 9;i >= 0;i--){
        for(int j = 1;j <= b[i];j++){
            fout << i;
        }
    }
    return 0;
}
