#include<bits/stdc++.h>
#define ll long long
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
using namespace std;
const int N=1e3+30;
int n,m;
int a[N];
const int dx[5]={0,0};
const int dy[5]={1,-1};
bool check(int x,int y){
	return 1<=x && x<=n && 1<=y && y<=m; 
}
int main(){
	file(seat);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ming=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	int num=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==ming){
			num=i;
			break;
		}
	} 
	int row=1,col=1;
	int pos=0;
	for(int i=1;i<num;i++){
//		cout<<row<<" "<<col<<endl;
		int rr=row+dx[pos];
		int cc=col+dy[pos];
//		cout<<rr<<" "<<cc<<endl;
//		cout<<endl;
		if(check(rr,cc)){
			row=rr,col=cc;
		}
		else{
			pos=1-pos;
			row=row+1; 
			col=col;
		}
	}
	cout<<row<<" "<<col;
	return 0;
}
//蛇形填数有实力的
//froepen   ；   sate   stae  ates  __int128   y0 y1 yn j0 j1 jn  %i64d

//骗你的，迷惑行为大赏来的 
