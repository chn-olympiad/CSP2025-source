#include<bits/stdc++.h> 
using namespace std;
long long n,m,k,ans=LONG_LONG_MAX;
vector<vector<bool> > city;
vector<pair<pair<long long,long long>,long long> > road;
vector<pair<long long,vector<long long> > > country;
bool check(){
	for(long long i=1;i<n;i++){
		if(!city[0][i]){
			return 0;
		}
	}
	return 1;
}
void f2(long long bh,long long money){
	if(true||bh==k){
		if(check()){
			ans=min(ans,money);
		}
	}
}
void f1(long long bh,long long money){
	if(bh>=m){
		f2(0,money);
		return;
	}
	cout<<bh;
	f1(bh+1,money);
	if(city[road[bh].first.first][road[bh].first.second]){
		return;
	}
	vector<vector<bool> > temp_city;
	temp_city=city;
	deque<pair<long long,long long> > q;
	q.push_back(road[bh].first);
	pair<long long,long long> new_q;
	while(!q.empty()){
		//cout<<q.front().first<<q.front().second<<'\n';
		city[q.front().first][q.front().second]=1;
		if(!city[q.front().second][q.front().first]){
			new_q.first=q.front().second;
			new_q.second=q.front().first;
			q.push_back(new_q);
		}
		for(int i=0;i<n;i++){
			if(city[q.front().first][i]!=city[i][q.front().second]){
				if(city[q.front().first][i]){
					new_q.first=i;
					new_q.second=q.front().second;
					q.push_back(new_q);
				}
				else{
					new_q.second=i;
					new_q.first=q.front().first;
					q.push_back(new_q);
				}
			}
		}
		q.pop_front();
	}
	f1(bh+1,money+road[bh].second);
	city=temp_city;
}
int main(){
	ifstream in("road.in");
	ofstream out("road.out");
	in>>n>>m>>k;
	if(true){
		vector<vector<bool> > v2(n,vector<bool>(n,0));
		city=v2;
	}
	for(long long i=0;i<m;i++){
		pair<pair<long long,long long>,long long> new_road;
		in>>new_road.first.first>>new_road.first.second>>new_road.second;
		new_road.first.first--;
		new_road.first.second--;
		road.push_back(new_road);
	} 
	for(long long i=0;i<k;i++){
		pair<long long,vector<long long> > new_country;
		in>>new_country.first;
		for(long long j=0;j<n;j++){
			long long temp;
			in>>temp;
			new_country.second.push_back(temp);
		}
		country.push_back(new_country);
	}
	f1(0,0);
	out<<ans;
	return 0;
}
