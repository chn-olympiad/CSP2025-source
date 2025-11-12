#include <fstream>
#include <algorithm>
#define maxn 1000001
std::ifstream fin("number.in");
std::ofstream fout("number.out");
short num[maxn];
int main() {
	std::string s;
	fin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[++sum]=s[i]-'0';
		}
	}
	std::sort(num+1,num+1+sum);
	for(int i=sum;i>=1;i--){
		fout<<num[i];
	}
}