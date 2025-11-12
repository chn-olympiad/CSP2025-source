#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool c(pair<int,int>a,pair<int,int>b){
	return a.first>b.first; 
}

int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,maxn,s,m,sum = 0,mm;
	cin>>t;
	int a[100000][3];
	vector<pair<int,int>>to_1; 
	vector<pair<int,int>>b1;
	vector<pair<int,int>>b2;
	vector<pair<int,int>>b3;
	while(t--){
		cin>>n;
		sum = 0;
		b1.clear();
		b2.clear();
		b3.clear();
		for(int i = 0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			maxn = max(a[i][0],a[i][1]);
			if(a[i][2] > maxn){
				mm = maxn;
			}else{
				if(a[i][0]<a[i][1])&&maxn = a[i][0]){
					if(a[i][1]<a[i][2]){
						mm = a[i][2]
					}
					else mm = a[i][1]; 
				}
			}
			maxn = max(maxn,a[i][2]);
			to_1[i] = {maxn-mm,i};
			if(maxn == a[i][0]){
				b1.push_back({maxn,i});
			}else if(maxn == a[i][1]){
				b2.push_back({maxn,i});
			}else{
				b3.push_back({maxn,i});
			}
		}
		sort(to_1.begin(),to_1.end(),c);
		cout<<"a";
		if(b1.size()>n/2){
			s = b1.size()-1-n/2;
			for(int i = 0;i<n;i++){
				if(s==0)break;
				if(to_1[i].first == a[to_1[i].second][0]-a[to_1[i].second][1]){
					b2.push_back({a[to_1[i].second][1],to_1[i].second});
					s--;
				}
				else if(to_1[i].first == a[to_1[i].second][0]-a[to_1[i].second][2]){
					b3.push_back({a[to_1[i].second][2],to_1[i].second});
					s--;
				}
				for(int j = 0;j<b1.size();j++){
					if(b1[j].second==to_1[i].second){
						b1[j].first = 0;
						break;
					}
				}
			}
		}
		if(b2.size()>n/2){
			s = b2.size()-1-n/2;
			for(int i = 0;i<n;i++){
				if(s==0)break;
				if(to_1[i].first == a[to_1[i].second][1]-a[to_1[i].second][0]){
					b1.push_back({a[to_1[i].second][0],to_1[i].second});
					s--;
				}
				else if(to_1[i].first == a[to_1[i].second][1]-a[to_1[i].second][2]){
					b3.push_back({a[to_1[i].second][2],to_1[i].second});
					s--;
				}
				else{
					continue;
				}
				for(int j = 0;j<b2.size();j++){
					if(b2[j].second==to_1[i].second){
						b2[j].first = 0;
						break;
					}
				}
			}
		}
		if(b3.size()>n/2){
			s = b3.size()-1-n/2;
			for(int i = 0;i<n;i++){
				if(s==0)break;
				if(to_1[i].first == a[to_1[i].second][2]-a[to_1[i].second][1]){
					b2.push_back({a[to_1[i].second][1],to_1[i].second});
					s--;
				}
				else if(to_1[i].first == a[to_1[i].second][2]-a[to_1[i].second][0]){
					b1.push_back({a[to_1[i].second][0],to_1[i].second});
					s--;
				}
				else{
					continue;
				}
				for(int j = 0;j<b3.size();j++){
					if(b3[j].second==to_1[i].second){
						b3[j].first = 0;
						break;
					}
				}
			}
		}
		//cout<<b1.size()<<b2.size()<<b3.size();
		for(int i = 0;i<b1.size();i++){
			sum+=b1[i].first;
		}
		for(int i = 0;i<b2.size();i++){
			sum+=b2[i].first;
		}
		for(int i = 0;i<b3.size();i++){
			sum+=b3[i].first;
		}
		cout<<sum<<"\n"; 
	}
	
	return 0;
}
