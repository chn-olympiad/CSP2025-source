#include<bits/stdc++.h>
using namespace std;
int n,m,pos,x,c=1,r=1,cnt;
bool f,b;
struct node{
	int score,id;
}a[105];
bool cmp(node p,node q){
	return p.score>q.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i].score,a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			pos=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cnt++;
			if(cnt==pos){
				cout<<c<<" "<<r;
				f=1;
				break;
			}
			if(i%2!=0&&r<n)r++;
			else if(i%2==0&&r>1)r--;
			
		}
		if(f)break;
		c++;
		b=1;
	}
	return 0;
}
