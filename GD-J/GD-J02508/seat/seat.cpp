#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int>a(n*m+1);
	for(int i=1;i<=n*m;i++) cin >> a[i];
	int cnt=a[1];
	sort(a.begin()+1,a.end(),cmp);
	int ans_x=1,ans_y=1;
	bool flag=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			cout << ans_x << ' ' << ans_y;
			return 0;
		}
		if(i%m==0) ans_x++,flag=!flag;
		else if(flag) ans_y--;
		else ans_y++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

