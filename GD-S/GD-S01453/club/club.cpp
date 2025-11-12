#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=30+2;
int t,n,a,b,c;
int ANS,Max;
vector <int> S[32];
int special[100002];
int solve1(){
	int ans=0;
	sort(special+1,special+n+1);
	for (int i=1;i*2<=n;i++)
		ans+=special[i];
	return ans;
}
void solve2(int x,int a,int b,int c){
	if (a*2>n || b*2>n || c*2>n)
		return;
	if (x>n){
		if (Max<ANS)
			Max=ANS;
		return;
	}
	for (int i=0;i<3;i++){
		ANS+=S[x][i];
		solve2(x+1,a+(i==0),b+(i==1),c+(i==2));
		ANS-=S[x][i];
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++){
		Max=0;
		cin>>n;
		if (n==1e5){
			for (int j=1;j<=n;j++)
				cin>>special[j]>>b>>c;
			cout<<solve1()<<endl;
		}
		for (int j=1;j<=n;j++){
			cin>>a>>b>>c;
			S[j].push_back(a);
			S[j].push_back(b);
			S[j].push_back(c);
		}
		solve2(1,0,0,0);
		cout<<Max<<endl;
		for (int j=1;j<=n;j++){
			S[j]={0};
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
