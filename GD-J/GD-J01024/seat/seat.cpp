#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r;
	cin>>c>>r;
	set<int> sb;
	int goal;
	cin>>goal;
	int s;
	sb.insert(goal);
	for(int i=1;i<c*r;i++){
		cin>>s;
		sb.insert(s);
	}int i=1;
	for(auto x:sb){
		if(x==goal){
			int k=c*r-i;
			if(((k/c)+1)%2==1)
				cout<<(k/c)+1<<" "<<(k%r)+1;
			if(((k/c)+1)%2==0)
				cout<<(k/c)+1<<" "<<r-(k%r);
			return 0;
		}
		i++;
	}
	return 0;
}
