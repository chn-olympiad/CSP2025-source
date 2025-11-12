#include <bits/stdc++.h>
using namespace std;

#define mod1 998
#define mod2 244
#define mod3 353

// by Junxuan Zhu
// 2025/ 11/ 1

inline void PrintVector(vector<int> a);

bool check(vector<int> ns){
	vector<int> temp = ns;
	sort(temp.begin(), temp.end());
	int theBack = temp.back();
	int Max = theBack * 2;
	int Allvalue = 0;

	for (int i=0;i<temp.size();i++){
        Allvalue += temp[i];
	}

	return Allvalue > Max;
}

vector<int> nums(0); // input's list
int cnt = 0;
int n;
//bool flag = 0; // 是否到达n的m边界

void removeEndSpaceOnVec(vector<int>& a){
    for (int i=0;i<a.size();i++){
        if (a.back() == 0) {
            a.pop_back();
        }
    }
    //cout << "Space removed!" <<endl;
}

// m >= 3
void solve(int now, int m, vector<int> nn){
//	cout << "Running new solve" << endl;
//	cout << "nn[]=";
	PrintVector(nn);
//	cout << "Setting :"<<endl << "Now = " << now << ", m = " << m << endl;

	if (m == n){
//		cout << "Solve: m == n exit solve func" << endl;
		return;
	}

	for (int i=now;i<m;i++){
		nn[i] = nums[i];
//		cout << "Add value: " << nums[i] << endl;
	}
//	cout << endl;

	vector<int>n2 = nn;
	removeEndSpaceOnVec(n2);
//	cout << "n2: ";PrintVector(n2);
	if (check(n2)) cnt ++;
//	cout << "n2.back() = " << n2.back() <<", nums.back() = "<< nums.back()<<endl;
	if ((n2.back() == nums.back()) or (now >= m)){
		m ++;
//		cout << "m ++" << endl;
	}
	solve(now + 1, m, nn);

//	cout << "one solve func was over" << endl;
}

inline void PrintVector(vector<int> a){
//	cout << "list = [";
	for (int i=0;i<a.size();i++){
        cout << a[i] << (i+1==a.size() ? ']' : ',');
	}
	cout << endl;
}

int main(){
	freopen(".in", "r", stdin);
	freopen(".ans", "w", stdout);

	cin >> n;

	for (int i=1; i<=n; i++){
		int a;
		cin >> a;
		nums.push_back(a);
	}

	//PrintVector(nums);

	vector<int> temp(n+1, 0);
	solve(0, 3, temp);

	cout << cnt << endl;

	return 0;
}
