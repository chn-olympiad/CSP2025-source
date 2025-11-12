#include<bits/stdc++.h>
using namespace std;
const int N=1145;
int n,m;
pair<int,int> a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i].first,a[i].second=i;
	sort(a+1,a+n*m+1,greater<pair<int,int> >());
	int fac=2,x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].second==1){
			cout<<x<<" "<<y<<endl;
			break;
		}if(fac==0)	y--;
		else if(fac==1)	x++;
		else if(fac==2)	y++;
		
		if(fac!=1&&(y==1||y==n))	fac=1;
		else if(fac==1)	fac=(y==1?2:0);
	}
	fclose(stdin);
	fclose(stdout);
}/*
CICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICI
CICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICI
*/
