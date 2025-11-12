#include<bits/stdc++.h>
using namespace std;
int stud[105],b[105];
priority_queue<int> q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>stud[i],q.push(stud[i]);
	for(int i=1;i<=n*m;i++)b[i]=q.top(),q.pop();
	char flag='d';
	int nown=1,nowm=1;
	for(int i=2;i<=n*m;i++){
		if(flag=='d')nown++;
		else nown--;
		if(nown>n)nown--,nowm++,flag='u';
		else if(nown<1)nown++,nowm++,flag='d';
		if(b[i]==stud[1])break;
	}
	cout<<nowm<<" "<<nown<<"\n";
	return 0;
}
