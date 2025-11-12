#include<bits/stdc++.h>
using namespace std;
int n,k;//n为序列长度 k为每个区间权值为k 区间不可相交
vector<int>v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;int tmp;
	bool fla=true;bool fla2=true;
	for(int i=1;i<=n;i++){
		cin>>tmp;v.push_back(tmp);
		if(tmp!=1)fla=false;
		if(tmp>=2)fla2=false;
	}
	if(k==0&&fla){//fla 全是0 
		 cout<<n/2;
	}
	else if(k==1&&fla2){//fla2 全是0或1 
		
		int ans=0;
		for(int i=1;i<v.size();i++){
			if(v[i]!=v[i-1]){
				ans++;i+=1;
			}
		}
		
		int ans2=0;
		for(int i=0;i<v.size();i++){
			if(v[i]==k){
				ans2++;
			}
		}
		int ans_;
		
		ans_=max(ans,ans2);
		
		cout<<ans_;
	}
	else{
		int ans=0;
		for(int i=0;i<v.size();i++){
			if(v[i]==k){
				ans++;
			}
		}
		cout<<ans;
	}
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
