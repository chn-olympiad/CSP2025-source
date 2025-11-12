#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m=" ";
	cin>>n;
	for(int i=0;i<n;i++){
		if(n.size(i)==1 or n.size(i)==2 or n.size(i)==3 or n.size(i)==4 or n.size(i)==5 or n.size(i)==6 or n.size(i)==7 or n.size(i)==8 or n.size(i)==9 or n.size(i)==0){
			m=m+n.size(i);
		}
	}
	int a=" ";
	for(int i=0;i<m;i++){
		if(m.size(i)==9){
			a=a+m.size(i);
		}else if(m.size(i)==9){
			a=a+m.size(i);
		}else if(m.size(i)==8){
			a=a+m.size(i);
		}else if(m.size(i)==7){
			a=a+m.size(i);
		}else if(m.size(i)==6){
			a=a+m.size(i);
		}else if(m.size(i)==5){
			a=a+m.size(i);
		}else if(m.size(i)==4){
			a=a+m.size(i);
		}else if(m.size(i)==3){
			a=a+m.size(i);
		}else if(m.size(i)==2){
			a=a+m.size(i);
		}else if(m.size(i)==1){
			a=a+m.size(i);
		}else if(m.size(i)==0){
			a=a+m.size(i);
	}
	cout<<a;
	return 0;
}
