#include<bits/stdc++.h>
using namespace std;
int n,m;
int gj[11][11];
struct Node{
	int fs,s1,s2,id;
	bool ll;
}aaa[100100];
bool cmp(Node a,Node b){
	return a.fs > b.fs;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n * m;i++){
		cin>>aaa[i].fs;
	}
	aaa[1].ll = true;
	int idhh = 0;
	sort(aaa + 1,aaa + 1 + n * m,cmp);
	for(int i = 1;i <= n * m;i++){
		if(aaa[i].ll == true){
			idhh = i;
		}
	}
	for(int i = 1;i <= n;i++){
		if(i == 1){
			gj[1][1] = 1;
			for(int j = 2;j <= m;j++){
				if(j % 2 == 0){
					gj[1][j] = gj[1][j - 1] + (2 * n - 1);
				}else{
					gj[1][j] = gj[1][j - 1] + 1;
				}
			}
		}else if(i == n){
			gj[n][1] = n;
			for(int j = 2;j <= m;j++){
				if(j % 2 == 1){
					gj[n][j] = gj[n][j - 1] + (2 * n - 1);
				}else{
					gj[n][j] = gj[n][j - 1] + 1;
				}
			}
		}else{
			gj[i][1] = i;
			for(int j = 2;j <= m;j++){
				if(j % 2 == 1){
					gj[i][j] = gj[i][j - 1] + (i - 1) * 2 + 1;
				}else{
					gj[i][j] = gj[i][j - 1] + (n - i) * 2 + 1;
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(gj[i][j] == idhh){
				cout<<j<<' '<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
