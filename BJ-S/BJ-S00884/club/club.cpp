#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;

int n;
struct node{
	int sat[4];
	int pref[4];//学生的第n志愿
	
}stu[maxn];

bool operator< (const node &x, const node &y){
	return x.sat[x.pref[2]] < y.sat[y.pref[2]];
}

void adjust(node &x){
	pair<int,int> _pref1,_pref2,_pref3;
	_pref1.first = x.sat[1],_pref1.second = 1;
	_pref2.first = x.sat[2],_pref2.second = 2;
	_pref3.first = x.sat[3],_pref3.second = 3;
	pair<int,int> _pref[3] = {_pref1,_pref2,_pref3};
	sort(_pref,_pref+3);
	for(int i=2;i>=0;i--){
		x.pref[3-i] = _pref[i].second;
	}
	return;
}

//bool operator< (const node &x,const node &y){
//	if(x.sat[1] != y.say[1])return x.sat[1] < y.sat[1];
//	if(x.sat[2] != y.say[2])return x.sat[2] < y.sat[2];
//	if(x.sat[3] != y.say[3])return x.sat[3] < y.sat[3];
//	return 0;
//}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		int cnt[4] = {0,0,0,0},ans=0;
		for(int i=1;i<=n;i++){
			cin >> stu[i].sat[1] >> stu[i].sat[2] >> stu[i].sat[3];
			adjust(stu[i]);
			int maxsat = stu[i].sat[stu[i].pref[1]];
			ans += maxsat;
			stu[i].sat[1] -= maxsat;
			stu[i].sat[2] -= maxsat;
			stu[i].sat[3] -= maxsat;
		}
		sort(stu+1,stu+n+1);
//		cout << ans << endl;
		for(int i=1;i<=n;i++){
//			printf("%d %d %d, 第二志愿为%d\n",stu[i].sat[1],stu[i].sat[2],stu[i].sat[3],stu[i].pref[2]);	
			if(cnt[stu[i].pref[1]] >= n/2){
				ans += stu[i].sat[stu[i].pref[2]];
//				printf("接受调剂，进入%d\n",stu[i].pref[2]);
			}
			else {
				cnt[stu[i].pref[1]]++;
//				printf("进入%d\n",stu[i].pref[1]);
			}
//			printf("名额剩余:(%d,%d,%d)",n/2-cnt[1],n/2-cnt[2],n/2-cnt[3]);
		}
		cout << ans << endl;
//		cout << endl;
	}
	return 0;
}
