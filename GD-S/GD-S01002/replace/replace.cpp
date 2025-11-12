#include<iostream>
#include<vector>

using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	string sb;//you have no egg. 
	for(int i=0;i<(n+q)*2;i++){
		cin>>sb;
	}
	for(int i=2;i<=q+1;i++){
		cout<<n/2+i*2-4<<endl;
	}
	return 0;
}
