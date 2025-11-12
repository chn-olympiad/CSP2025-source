#include <iostream>//freopen!
#include <map>
using namespace std;
string s;
int sl;
map<char,int>mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		mp[s[i]]++;
	}
	for(int i=9;i>=0;i--){
		if(i!=0){
			for(int j=1;j<=mp[char(i+'0')];j++){
				cout<<i, sl++;
			}
		}else{
			if(sl==0){
				cout<<0;
				return 0;
			}else{
				for(int j=1;j<=mp[char(i+'0')];j++){
					cout<<i, sl++;
				}				
			}
		}
	}
	return 0;
}
