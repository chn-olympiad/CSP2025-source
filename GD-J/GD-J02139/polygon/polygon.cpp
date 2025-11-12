#include<bits/stdc++.h>
#define int long long
using namespace std;

bool compare(int c,int d) {
	return c>d; 
}

bool canp(vector<int> t){
	int m=[t]{
		int tmp=0;
		for(auto i:t) if(i>tmp) tmp=i;
		return tmp;
	}();
	int s=[t]{
		int tmp;
		for(auto i:t) tmp+=i;
		return tmp;
	}();
	return s>2*m;
}

int jc(int n){
	int cnt=1;
	for(int i=n;i>=0;i--){
		cnt *= i;
	}
	return cnt;
} 



vector<int> a;

signed main() {
	//freopen("polygon.in", "polygon.out", stdin);
	//freopen("polygon.in", "polygon.out", stdout);
	
	int n,tmp,cnt=0;
	cin>>n;
	
	
	
	for(int i=0;i<n;i++) {
		cin>>tmp;
		a.push_back(tmp);
	}
	
	sort(a.begin(), a.end(), compare);
	

	for(int i=3;i<n;i++) {
		/*
			
			temp.clear();
			for(auto lj:a) temp.push(lj);
			vector<int> t;
			
			for(int j=0;j<i;j++){
				while(t.size()==3) {
					t.push_back(temp.top());
					temp.pop();
				}
			}

		*/
		

		
		for(int j=0;j<n;j++) {
			
			int mb=a.at(j);
			vector<int> t;
			priority_queue<int> temp;
			for(auto lj:a) temp.push(lj);
			
			while(t.size==i){
				t.push_back(temp.top());
				temp.pop();
			}
		}
	}

	
	cout<<((temp.size()%998)%244)%353;
	
	return 0;
}
