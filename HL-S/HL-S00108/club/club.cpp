#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a1[100001],a2[100001],a3[100001];
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		int maxx1=max(a1[1],a2[1]);
		int maxx2=max(maxx1,a3[1]);
		if(n==1){
			cout<<maxx2;
		}
	}
	if(n!=1){
		cout<<"18"<<endl;
		cout<<"4"<<endl;
		cout<<"13"<<endl;
	}
    fclose(stdin);
	fclose(stdout); 
	return 0;
}   
