#include<bits/stdc++.h>
using namespace std;
bool rev(const int a,const int b){
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,score[101],s_ind;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>score[i];
	}
	s=score[1];
	sort(score+1,score+n*m+1,rev);
	for(int i=1; i<=n*m; i++) {
		if(s==score[i]) {
			s_ind=i;
			break;
		}
	}
	int x=ceil(s_ind*1.0/n),y=0;
	y=s_ind-(x-1)*n;
	if(x%2==1)  //From up to down;
	{
		cout<<x<<" "<<y<<endl;
	}
	else 
	{
		y=n-y+1;
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}
