#include<bits/stdc++.h>
using namespace std;
int n,m,num,seat;
typedef struct Node{
	int mark;
	bool is;
}Node;
Node node[105];
bool cmp(const Node n1,const Node n2){
	return n1.mark>n2.mark;
}
int l,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=n*m;
	cin>>node[1].mark;
	node[1].is=true;
	for (int i=2;i<=num;i++){
		cin>>node[i].mark;
		node[i].is=false;
	}
	sort(node+1,node+1+num,cmp);
	for (int i=1;i<=num;i++){
		if (node[i].is){
			seat=i;
			break;
		}
	}
	
	l=seat%m;
	r=seat/m;
	if (seat==l||seat==n){
		cout<<1<<" "<<seat;
		return 0;
	}
	if (r%2==0){
		r++;
		cout<<r<<" "<<l;
		return 0;
	}
	if (r%2==1){
		r++;
		l=m-l+1;
		cout<<r<<" "<<l;
		return 0;
	}
	return 0;
}
