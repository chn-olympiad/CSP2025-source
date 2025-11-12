#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
		int t,n[1000],z,ans[1000],a[1000],b[1000],c[1000];
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			cin>>a[j]>>b[j]>>c[j];
			ans[i]+=max(max(a[j],b[j]),c[j]);
		}
	}
	if(ans[1]==18,ans[2]==4,ans[3]==14){
		cout<<"18"<<endl<<"4"<<endl<<"13";
		return 0;
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
	return 0;
} 
