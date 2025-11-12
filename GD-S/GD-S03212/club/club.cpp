#include <bits/stdc++.h>

using namespace std;

struct member{
	int a1 = 0;
	int a2 = 0;
	int a3 = 0;
	int maxa = 0;
	int sec = 0;
	
	void getmaxa(){
		int mm = 0;
		mm = max(this->a1,this->a2);
		mm = max(this->maxa,this->a3);
		if(mm == a1){
			maxa = 1;
		}else if(mm == a2){
			maxa = 2;
		}else{
			maxa = 3;
		}
	}
	
	void getsec(){
		switch(maxa){
			case 1:
				if(this->a2 >= this->a3){
					sec = 2;
				}else{
					sec = 3;
				}
				break;
			case 2:
				if(this->a1 >= this->a3){
					sec = 1;
				}else{
					sec = 3;
				}
				break;
			case 3:
				if(this->a2 >= this->a1){
					sec = 2;
				}else{
					sec = 1;
				}
				break;
		}
	}
};

struct test{
	vector<member> m;
	int maxpe = 0;
};

/* *************************** */
void paixu(vector<int>* yuan){
	
}

int putin(test t){
	vector<int> v1,v2,v3;
	for(int i = 0;i < t.m.size();i++){
		switch(t.m[i].maxa){
			case 1:
				v1.push_back(t.m[i].a1);
				break;
			case 2:
				v2.push_back(t.m[i].a2);
				break;
			case 3:
				v3.push_back(t.m[i].a3);
				break;
		}
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	sort(v3.begin(),v3.end());
	member d1,d2;
	
}

int main(){

	freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	int t;
	vector<int> ans;
	cin >> t;
	vector<test> store1;
	for(int i = 0; i < t; i++){
		member m1;
		test t1;
		int n = 0;
		cin >> n;
		t1.maxpe = n/2;
		for(int j = 0; j < n; j++){
			cin >> m1.a1 >> m1.a2 >> m1.a3;
			m1.getmaxa();
			m1.getsec();
			t1.m.push_back(m1);
		}
		store1.push_back(t1);
	}
	for(int i = 0; i < store1.size();i++){
		ans.push_back(putin(store1[i]));
	}
	
	return 0;
} 
