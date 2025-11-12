#include<bits/stdc++.h>
using namespace std;

struct Student{
	int a,b,c;
}students[100005];

struct Addition{
	long long add;
	long long to;
	long long id;
}addition[200010];
bool is_student_use[100005];
map<int,pair<int,int>> mp;

int fir , sec , thir;

bool cmp(Addition a , Addition b){
	if(a.add == b.add and a.to == b.to){
		int a_id = a.id;
		int b_id = b.id;
		int another_a = a.to + 1 % 3;
		if(another_a == 0) another_a = 1;
		int another_b = b.to + 1 % 3;
		if(another_b == 0) another_b = 1;
		if(another_a == 1){
			another_a = mp[a_id].first;
		}else{
			another_a = mp[a_id].second;
		}
		if(another_b == 1){
			another_b = mp[b_id].first;
		}else{
			another_b = mp[b_id].second;
		}
		return another_a < another_b;
	}
	return a.add > b.add;
}

int main(){
	
	freopen("club.in", "r" , stdin);
	freopen("club.out" ,"w" , stdout);
	
	int t;
	cin >>  t;
	
	while(t--){
		memset(is_student_use , false , sizeof(is_student_use));
		int n;
		long long base_ans = 0;
		fir = 0;
		sec = 0;
		cin >> n;
		
		thir = n;
		for(int i = 1;i<=n;i++){
			cin >> students[i].a >> students[i].b >> students[i].c;
			base_ans += students[i].c;
		}
		int sizeof_addition = 0;
		for(int i = 1;i<=n;i++){ //遍历第 i 个同学去其他学院 
			//第一学院
			int fir_add = students[i].a - students[i].c;
			//第二学院
			int sec_add = students[i].b - students[i].c;
			++sizeof_addition;
			addition[sizeof_addition] = {fir_add , 1 , i};
			mp[i].first = fir_add;
			++sizeof_addition;
			addition[sizeof_addition] = {sec_add , 2 , i};
			mp[i].second = sec_add;
		}
		
		sort(addition+1 , addition + sizeof_addition + 1 , cmp);
		
		//调试
		for(int i = 1;i<=sizeof_addition;i++){
			int add = addition[i].add;
			int to = addition[i].to;
			int id = addition[i].id;
			if(add < 0 and thir <= n/2){
				break;
			}
			if(to == 1){
				if(is_student_use[id] == false){
					if(fir < n/2){
						base_ans += add;
						fir ++;
						thir --;
						is_student_use[id] = true;
					}
				}
			}else{
				if(is_student_use[id] == false){
					if(sec < n/2){
						base_ans += add;
						sec ++;
						thir --;
						is_student_use[id] = true;
					}
				}
			}
		}
		cout << base_ans << endl;		
	}	
	
	return 0;
} 
