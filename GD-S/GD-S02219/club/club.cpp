#include<bits/stdc++.h>
using namespace std;
struct Member{
	int i,j,k;
};
vector<Member> a;
bool cmp1(Member a,Member b){
	return a.i > b.i;
}
bool cmp2(Member a,Member b){
	return a.j > b.j;
}
bool cmp3(Member a,Member b){
	return a.k > b.k;
}
int t;
namespace specialA{
	void solve(int n){
		cout << n/2 << endl;
	}
}
namespace specialB{
	void solve(int n,vector<Member> a){
		int cnt=0;
		int ans1=0,ans2=0;
		sort(a.begin(),a.end(),cmp1);
		for(auto i : a){
			cnt++;
			if(cnt>n/2)ans1+=i.j;
			else ans1+=i.i;
		}
		sort(a.begin(),a.end(),cmp2);
		for(auto i : a){
			cnt++;
			if(cnt>n/2)ans2+=i.i;
			else ans2+=i.j;
		}
		cout << max(ans1,ans2) << endl;
	}
}
void solve(){
	int n;cin >> n;
	a.clear();
	int ndiv2 = n/2;
	int isum=0,jsum=0,ksum=0;
	bool specialAFlag = 1;
	bool specialBFlag = 0;
	for(int i = 1;i <= n;i++){
		int i_,j,k;cin >> i_ >> j >> k;
		if(j || k) specialAFlag=0;
		if(k) specialBFlag = 0;
		isum += i_;jsum += j;ksum += k;
		a.push_back({i_,j,k});
	}
	if(specialAFlag){
		specialA::solve(n);
		return;
	}
	if(specialBFlag){
		specialB::solve(n,a);
		return;
	}
	vector<Member> d[4];
	int sum1 = 0,sum2 = 0,sum3 = 0;
	for(auto i : a){
		if(i.i > i.j && i.i > i.k) d[1].push_back(i),sum1+=i.i;
		if(i.j > i.i && i.j > i.k) d[2].push_back(i),sum2+=i.j;
		if(i.k > i.i && i.k > i.j) d[3].push_back(i),sum3+=i.k;
	}
	sort(d[1].begin(),d[1].end(),cmp1);
	sort(d[2].begin(),d[2].end(),cmp2);
	sort(d[3].begin(),d[3].end(),cmp3);
	bool flag = 0;
	do{
		flag = 0;
		if(d[1].size()>ndiv2){
			flag = 1;
			Member tmp = d[1][d[1].size()-1];
			sum1-=tmp.i;
			d[1].pop_back();
			if(tmp.j>tmp.k){
				d[2].push_back(tmp);
				sum2+=tmp.j;
			}
			else{
				d[3].push_back(tmp);
				sum3+=tmp.k;
			}
		}
		if(d[2].size()>ndiv2){
			flag = 1;
			Member tmp = d[2][d[2].size()-1];
			sum1-=tmp.j;
			d[2].pop_back();
			if(tmp.i>tmp.k){
				d[1].push_back(tmp);
				sum1+=tmp.i;
			}
			else{
				d[3].push_back(tmp);
				sum3+=tmp.k;
			}
		}
		if(d[3].size()>ndiv2){
			flag = 1;
			Member tmp = d[3][d[3].size()-1];
			sum1-=tmp.k;
			d[3].pop_back();
			if(tmp.i>tmp.j){
				d[1].push_back(tmp);
				sum1+=tmp.i;
			}
			else{
				d[2].push_back(tmp);
				sum2+=tmp.j;
			}
		}
	}while(flag);
	cout << (sum1+sum2+sum3) << endl; 
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)solve();
	return 0;
} 
