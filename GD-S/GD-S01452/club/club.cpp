/*
TASUKETE_ERINNNNNNNNNN!!!!!!!!!!!!!!!

有思路了！14：44

大样例全过了，好耶。
THANKYOU_ERINNNNNNNNNN!!!!!!!!!!!!!!!

虽然但是T1用反悔贪心是不是有点过了，我总觉得我想复杂了。15：12
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 110000;
struct student{
    int first, first_id, second, second_id, third, third_id;
    void reset() { first = first_id = second = second_id = third = third_id = 0; }
    void insert(int x, int id){
        if(x >= first) return second = first, second_id = first_id, first = x, first_id = id, void();
        if(x >= second) return third = second, third_id = second_id, second = x, second_id = id, void();
        third = x, third_id = id;
    }
} all_student[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> department[5];
int T, n, a, liminality, ans;
void init(){
	for(int i = 1; i <= 3; i++) while(department[i].size()) department[i].pop();
	for(int i = 1; i <= n; i++) all_student[i].reset();
	ans = 0;
}
void work(){
    cin >> n; liminality = n / 2;
    init();
    for(int i = 1; i <= n; i++) for(int j = 1; j <= 3; j++) cin >> a, all_student[i].insert(a, j);
    for(int i = 1; i <= n; i++){
        student s = all_student[i];
        if(department[s.first_id].size() >= liminality){
            int this_contribution = s.first - s.second;
            if(this_contribution + department[s.first_id].top().first > 0){
                pair<int, int> tmp = department[s.first_id].top(); department[s.first_id].pop();
                ans = ans + tmp.first + s.first;
                department[s.first_id].push({s.second - s.first, i});
                student getting_sacked = all_student[tmp.second];
                department[getting_sacked.second_id].push({getting_sacked.third - getting_sacked.second, tmp.second});
                continue;
            }
            department[s.second_id].push({s.second - s.third, i});
            ans += s.second;
            continue;
        }
        department[s.first_id].push({s.second - s.first, i});
        ans += s.first;
    }
    cout << ans << '\n';
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	for(int i = 1; i <= T; i++) work();
	cout << flush;
}
