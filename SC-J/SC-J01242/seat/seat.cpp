#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	int fs;
	bool is=false;
};
vector<Node> a;
bool compare(Node a,Node b){
	return a.fs>b.fs;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,now;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		Node tmp;
		cin>>tmp.fs;
		if(i==0)tmp.is=true;
		a.push_back(tmp);
	}
	sort(a.begin(),a.end(),compare);
	for(int i=0;i<n*m;i++){
		if(a[i].is){
			now=i+1;
			break;
		}
	}
	if(now<=n){
		cout<<1<<" "<<now;
	}else if(now%n==0){
		int nn=now/n;
		if(nn%2==0){
			cout<<nn<<" "<<0;
		}else{
			cout<<nn<<" "<<n;
		}
	}else{
		int nn=(now-(now%n))/n+1;
		if(nn%2==0){
			cout<<nn<<" "<<n-(now%n)+1;
		}else{
			cout<<nn<<" "<<now%n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}