#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,length[11],leng[101];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>length[i];
		leng[length[i]]++;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	int max=-1,all=0;
	for(int i=0;i<n;i++){
		all=all+length[i];
		if(length[i]>max)  max=length[i];
	}
	if(all>max*2){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	
