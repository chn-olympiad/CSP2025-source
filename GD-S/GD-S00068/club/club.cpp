#include<bits/stdc++.h>
using namespace std;
vector<int > a(100100);
vector<int > b(100100);
vector<int > c(100100);
int n;
int ma;
int solve(int ra,int rb,int rc,int ans,int st,int now,int no){
	if(st==n){
		if(ans<now)
			return now;
		else
			return 0;
	}
	if(ra<ma){
		ans=max(ans,solve(ra+1,rb,rc,ans,st+1,now+a[no],no+1));
	} 
	if(rb<ma){
		ans=max(ans,solve(ra,rb+1,rc,ans,st+1,now+b[no],no+1));
	}
	if(rc<ma){
		ans=max(ans,solve(ra,rb,rc+1,ans,st+1,now+c[no],no+1));
	}
	
	return ans;
}
int main(){
	freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ma=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		cout<<solve(0,0,0,0,0,0,1)<<endl;
	}
	fclose(stdout);
	fclose(stdin);
	
	return 0;
}
//Ren5Jie4Di4Ling5%
