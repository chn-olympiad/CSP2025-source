#include<bits/stdc++.h>
using namespace std;
struct Stu{
	int a,id;
}stu[105];
int n,m,s,R,ansx,ansy;
bool cmp(Stu p,Stu q){
	return p.a>q.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++)cin>>stu[i].a,stu[i].id=i;
	sort(stu+1,stu+1+s,cmp);
	for(int i=1;i<=s;i++){
		if(stu[i].id==1){
			R=i;break;
		}
	}
	ansx=ansy=1;
	for(int i=2;i<=R;i++){
		if(ansx%2){
			if(ansy<n)ansy++;
			else ansx++;
		}
		else{
			if(ansy>1)ansy--;
			else ansx++;
		}
	}
	cout<<ansx<<" "<<ansy;
	return 0;
} 
