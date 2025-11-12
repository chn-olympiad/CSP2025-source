#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
const long long N=1e6+1000;
int ans[N];

bool cmp(int a,int b){
	return a>=b;
}

int main(){
	ifstream fin("number.in");
	ofstream fou("number.out");
	string s; fin>>s;
	for(int i=0; i<s.size(); i++){
		if(s[i]>='0' && s[i]<='9'){
			ans[++ans[0]]=int(s[i]-'0');
		}
	}
	sort(ans+1,ans+ans[0]+1,cmp);
	for(int i=1; i<=ans[0]; i++){
		fou<<ans[i];
	}
	return 0;
}
