#include<bits/stdc++.h> 
using namespace std;
int c1[100002],c2[100002],c3[100002];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		int sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>c1[i]>>c2[i]>>c3[i];
		}
		sort(c1+1,c1+n+1,cmp);
		sort(c2+1,c2+n+1,cmp);
		sort(c3+1,c3+n+1,cmp);
		sum+=c1[1]+c2[1]+c3[1];
		if(n%3!=0){
			sum+=max(c1[2],max(c2[2],c3[2]));
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
