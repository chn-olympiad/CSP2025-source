#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,a,s1;
	list<int> s;
	cin >> x >> y; 
	for(int i;i<=x*y;i++){
		cin >> a;
		if(i==0){
			s1=a;
		}
		s.push_back(a);	
	}
	s.sort();
	for(int j=1;j<=x;j++){
		for(int q=1;q<=y;q++){;
			
		}
	}
	return 0;
}
