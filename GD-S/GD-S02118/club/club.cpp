//Good Luck
//RP += INF
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define endl '\n'
#define QRQ 1
#define int long long
int whoismax(int a,int b,int c){
	if (a>=max(b,c)) return 0;
	if (b>=max(a,c)) return 1;
	if (c>=max(a,b)) return 2;
}
int max3(int a,int b,int c){
	return max(max(a,b),c);
}
int mid3(int a,int b,int c){
	if (a>=b&&b>=c) return b;
	if (a>=c&&c>=b) return c;
	if (b>=a&&a>=c) return a;
	if (b>=c&&c>=a) return c;
	if (c>=a&&a>=b) return a;
	if (c>=b&&b>=a) return b;
}
struct node{
	int a,b,c;
};
node a[100005];
vector<int> a1[3];
int sum;
bool cmp(int x,int y){
	int deta = mid3(a[x].a,a[x].b,a[x].c)-max3(a[x].a,a[x].b,a[x].c);
	int detb = mid3(a[y].a,a[y].b,a[y].c)-max3(a[y].a,a[y].b,a[y].c);
	return deta>=detb;
}
signed main(){
	if (QRQ){
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
	}
    int t;cin >> t;
    while (t--){
		memset(a,0,sizeof a);
		a1[0].clear();
		a1[1].clear();
		a1[2].clear();
		sum=0;
		int n;
		cin >> n;
		for (int i = 1;i<=n;i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
			if (a[i].a>=max(a[i].b,a[i].c)){a1[0].push_back(i);sum+=a[i].a;}
			else if (a[i].b>=max(a[i].a,a[i].c)){a1[1].push_back(i);sum+=a[i].b;}
			else {a1[2].push_back(i);sum+=a[i].c;}
		}
		if (max3(a1[0].size(),a1[1].size(),a1[2].size())>n/2){
			int wim = whoismax(a1[0].size(),a1[1].size(),a1[2].size());
			sort(a1[wim].begin(),a1[wim].end(),cmp);
			int n2m = a1[wim].size() - n/2;
			for (int i = 0;i<n2m;i++){
				int x =a1[wim][i];
				sum+=mid3(a[x].a,a[x].b,a[x].c)-max3(a[x].a,a[x].b,a[x].c);
			}
		}
		cout << sum << endl;
	}
}
