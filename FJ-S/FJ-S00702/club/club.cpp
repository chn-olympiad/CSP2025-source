#include<bits/stdc++.h>
using namespace std;
int s[100005][4];
int t[4], q[100005], tot=0;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out","w", stdout);
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
while(T--){
	int n, mx=0;
	cin >> n;
	t[0]=t[1]=t[2]=tot=0;
	for(int i=1;i<=n;i++){
		cin >> s[i][0] >> s[i][1] >> s[i][2];
		if(s[i][0]>s[i][1]&&s[i][0]>s[i][2]){
			t[0]++;s[i][3]=0;
		}
		if(s[i][1]>s[i][0]&&s[i][1]>s[i][2]){
			t[1]++;s[i][3]=1;
		}
		if(s[i][2]>s[i][0]&&s[i][2]>s[i][1]){
			t[2]++;s[i][3]=2;
		}
		mx+=max(s[i][0],max(s[i][1],s[i][2]));
	}int h=-1;
	for(int i=0;i<3;i++){
		if(t[i]>n/2){
			h=i;
		}//cout << t[i] << ":" << n/2 << "|\n";
	}if(h==-1){
		cout <<  mx << "\n";
	}else{
		for(int i=1;i<=n;i++){
			if(s[i][3]==h){
				//cout << tot << ":" << i<<":" << s[i][h] << ":" << s[i][(h+1)%3] << s[i][(h+2)%3] << "->" << s[i][h]-max(s[i][(h+1)%3],s[i][(h+2)%3]) << "\n";
				q[++tot]=s[i][h]-max(s[i][(h+1)%3],s[i][(h+2)%3]);
			}
		}sort(q+1,q+1+tot);
		for(int i=1;i<=t[h]-n/2;i++){
			//cout << mx << "-" << q[i] << "\n";
			mx-=q[i];
		}cout << mx << "\n";
	}
}} 
