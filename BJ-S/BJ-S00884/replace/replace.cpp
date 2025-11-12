#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+7;

vector<int> find(string s,string target){
	vector<int> ret;
	for(int i=0;i<s.length();i++){
		bool flag = 1;
		for(int j=0;j<target.length();j++){
			if(s[i+j]!=target[j]){
				flag=0;
				break;
			}
		}
		if(flag)ret.push_back(i);
	}
	return ret;
}

string rep[maxn],res[maxn];
int dif[maxn];
int n,q;
vector<int> origin_place,target_place;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> rep[i] >> res[i];
		for(int j=0;j<rep[i].length();j++){
			if(rep[i][j]!=res[i][j])dif[i]++;
		}
	}
	while(q--){
		string origin,target;
		int DIF=0;
		cin >> origin >> target;
		if(origin.length()!=target.length()){
			cout << 0 << endl;
			continue;
		}
		for(int i=0;i<origin.length();i++){
			if(origin[i]!=target[i])DIF++;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(dif[i]!=DIF)continue;
			origin_place = find(origin,rep[i]);
			target_place = find(target,res[i]);
			if(origin_place.size()==0||target_place.size()==0){
				continue;
			}
			for(int i=0,j=0;i<origin_place.size() && j<target_place.size();){
				if(origin_place[i] == target_place[j]) ans++,i++,j++;
				if(origin_place[i] > target_place[j]) j++;
				if(origin_place[i] < target_place[j]) i++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
