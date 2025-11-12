#include<bits/stdc++.h>
using namespace std;

#define file
#define infile "number.in"
#define outfile "number.out"

#ifdef file
#define cin ___cin___
#define cout ___cout___
ifstream ___cin___(infile);
ofstream ___cout___(outfile);
#endif

vector<long long>cnt;

string str;

int main(){
	cin>>str;
	cnt.resize(15,0);
	for(int i = 0;i < str.size();i++){
		if('0'<=str[i]&&str[i]<='9'){
			int n = str[i]-'0';
			cnt[n]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		while(cnt[i]--){
			cout<<i;
		}
	}
	return 0;
}

