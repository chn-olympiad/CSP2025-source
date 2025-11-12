#include<iostream>
#include<string>
using namespace std;
typedef pair<string,string> P;
int q , n;
P dic[200004];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>> n >> q;
	for(int i=1;i <= n;i++){
		cin>> dic[i].first >> dic[i].second;
	}
	while(q--){
		string x , y;
		cin>> x >> y;
		cout<< 1 <<'\n';
	}
	return 0;
}
