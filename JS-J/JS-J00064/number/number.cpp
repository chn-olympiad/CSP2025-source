#include<fstream>
#include<string>
#include<algorithm>
std::ifstream fin("number.in");
std::ofstream fout("number.out");
std::string s;
int a[1000001];
int siz=0;
int main(){
    fin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[siz]=s[i]-'0';
            siz++;
        }
    }
    std::sort(a,a+siz);
    for(int i=siz-1;i>=0;i--){
        fout<<(int)a[i];
    }
}
