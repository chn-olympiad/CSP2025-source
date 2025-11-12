#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<fstream>
using namespace std ;
int main(){
	ofstream cout("replace.out") ;
	ifstream cin ("replace.in" ) ;
	int n , q ;
	cin >> n >> q ;
	vector<pair<string,string> > s(n) ; // 二元组
	for(auto &x : s){
		cin >> x.first >> x.second ;
	}
	vector<pair<string,string> > t (q) ; // 问题
	for(auto &x : t){
		cin >> x.first >> x.second ;
	}
	for(auto qx : t){
		//qx : 当前问题
		queue<string> q;
		q.push(qx.first) ;
		unordered_map<string,bool> m;
		m[qx.first] = true ;
		int ans = 0 ;
		while(!q.empty()){
			string x = q.front();q.pop();
			if(m.find(x)==m.end())continue ;
			for(auto tx : s){
				int k = x.find(tx.first) , l = tx.second.size() ;
				string y = x ;
				bool flag = false ;
				if(k!=-1){
					for(int i = 0 ; i < l ; i++){
						y[k+i] = tx.second[i] ;
					}
					if(y==qx.second){
						ans++;
					}else{
						q.push(y) ;
						m[y]=true;
					}
				}
			}
		}
		cout << ans << endl ;
	}
	return 0 ;
}