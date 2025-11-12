#include<bits/stdc++.h>
using namespace std;

struct sati{
	long long val;
	long long nid;
};

int t;
long long n;
sati s1[5], s2[5];

bool cmd(sati x, sati y){
	if(x.val > y.val) return true;
	return false;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >>t;
	while(t --){
		cin >>n;
		for(int i = 1; i <= 3; i ++){
			cin >>s1[i].val;
			s1[i].nid = i;
		}
		for(int i = 1; i <= 3; i ++){
			cin >>s2[i].val;
			s2[i].nid = i;
		}
		sort(s1+1, s1+3+1, cmd);
		sort(s2+1, s2+3+1, cmd);
		if(s1[1].nid != s2[1].nid){
			cout <<s1[1].val+s2[1].val <<"\n";
		}else{
			long long maxn = 0;
			maxn = max(maxn, s1[1].val+s2[2].val);
			maxn = max(maxn, s1[2].val+s2[1].val);
			cout <<maxn <<"\n";
		}
		
		/*for(int i = 1; i <= 3; i ++) cout <<s1[i].val <<" ";
		cout <<endl;
		for(int i = 1; i <= 3; i ++) cout <<s2[i].val <<" ";*/
	}
	
	return 0;
} 
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
