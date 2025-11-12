#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string qus,ans;
	map<string,string> edit;
	long long n,m;
	cin >> n >> m;
	for(long long i = 0;i < n;i++){
		string ta,tb;
		cin >> ta >> tb;
		edit[ta]=tb;
	}
	for(long long i = 0;i < m;i++){
		cin >> qus >> ans;
		long long sum = 0;
		if(qus.size() != ans.size()){
			cout << 0 << endl;
			continue;
		}
		for(long long j = 0;j < qus.size();j++){
			for(long long k = j;k < qus.size();k++){
				string edited=qus,find=qus.substr(j,k-j+1);
				if(edit.count(find)){
					for(long long ptr = 0;ptr <= k-j;ptr++){
						edited[j+ptr] = edit[find][ptr];
					}
					if(edited == ans){
						sum++;
					}
				}
			}
		}
		cout << sum << endl;
	}
	fclose(stdin);
	fclose(stdout);
}
