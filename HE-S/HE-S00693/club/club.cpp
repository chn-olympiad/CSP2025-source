#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int T=0;T<t;T++){
		int n;
		cin>>n;
		int people=n;
		people/=2;
		int score1[100010];
		int score2[100010];
		int score3[100010];
		for(int i=0;i<n;i++){
			cin>>score1[i]>>score2[i]>>score3[i];
		}
		sort(score1,score1+n,cmp);
		sort(score2,score2+n,cmp);
		sort(score3,score3+n,cmp);
		int score[150015];
		for(int i=0;i<people;i++){
			score[i]=score1[i];
		}
		for(int i=people;i<people*2;i++){
			score[i]=score2[i];
		}
		for(int i=people*2;i<people*3;i++){
			score[i]=score3[i];
		}
		sort(score,score+people*3,cmp);
		int summ=0;
		for(int i=0;i<people*3;i++){
			summ+=score[i];
		}
		cout<<summ<<endl;
	}
	return 0;
}

